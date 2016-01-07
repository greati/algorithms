#include "HashTbl.h"
#include <iostream>
#include <tuple>

using namespace std;

/**
* \brief Class that represents an account.
*/
class Account {
	public:
		typedef int AcctKeyV1;
		typedef std::pair<std::string, int> AcctKeyV2;
		typedef std::tuple<std::string, int, int, int> AcctKeyV3;
	
		std::string personName;
		int bankCod;
		int agencyNumber;
		int accountNumber;
		double balance;
		
		Account(string _personName, int _bankCode, int _agencyNumber, int _accountNumber, double _balance) : personName {_personName}, bankCod {_bankCode}, agencyNumber {_agencyNumber}, accountNumber {_accountNumber}, balance {_balance} {};
		
		Account() {};

		AcctKeyV1 getKeyV1() {
			return accountNumber;				
		}

		AcctKeyV2 getKeyV2() {
			return std::pair<std::string, int> {personName, accountNumber};	
		}

		AcctKeyV3 getKeyV3() {
			return std::tuple<std::string, int, int, int> {personName, bankCod, agencyNumber, accountNumber};	
		}
};

/**
 * \brief Hash method for Version 1
 * */
struct KeyHashV1 {
	std::size_t operator()(const Account::AcctKeyV1 & _k) const {
		return std::hash<int>()(_k);
	}
};

/**
 * \brief Hash method for Version 2
 * */
struct KeyHashV2 {
	std::size_t operator()(const Account::AcctKeyV2 & _k) const {
		return std::hash<std::string>()(_k.first) ^ std::hash<int>()(_k.second);
	}
};

/**
 * \brief Hash method for Version 3
 * */
struct KeyHashV3 {
	std::size_t operator()(const Account::AcctKeyV3 & _k) const {
		return (std::hash<std::string>()(std::get<0>(_k)) 
			^ std::hash<int>()(std::get<1>(_k))) 
			^ (std::hash<int>()(std::get<2>(_k))
			^ std::hash<int>()(std::get<3>(_k)));
	}
};

/**
 * \brief Comparison method for key Version 1 
 * */
struct KeyEqualV1 {
	std::size_t operator()(const Account::AcctKeyV1 & _k1, const Account::AcctKeyV1 & _k2) const {
		return (_k1 == _k2);
	}
};

/**
 * \brief Comparison method for key Version 2 
 * */
struct KeyEqualV2{ 
	std::size_t operator()(const Account::AcctKeyV2 & _k1, const Account::AcctKeyV2 & _k2) const {
		return (_k1.first == _k2.first && _k1.second == _k2.second);
	}
};

/**
 * \brief Comparison method for key Version 3 
 * */
struct KeyEqualV3 {
	std::size_t operator()(const Account::AcctKeyV3 & _k1, const Account::AcctKeyV3 & _k2) const {
		return (std::get<0>(_k1) == std::get<0>(_k2)) &&
		(std::get<1>(_k1) == std::get<1>(_k2)) &&
		(std::get<2>(_k1) == std::get<2>(_k2)) &&
		(std::get<3>(_k1) == std::get<3>(_k2));
	}
};

int main() {

	// Declaring accounts
	Account acc1 {"Joao", 1, 1, 1, 120.0};
	Account acc2 {"Pedro", 2, 2, 2, 230.0};
	Account acc3 {"Maria", 10, 3, 11, 10000.0};
	Account acc4 {"Paulo", 4, 4, 21, 2000.0};
	Account acc5 {"Carlos", 5, 5, 5, 220.50};

	std::cout << "----- TESTS FOR KEY VERSION 1 -----" << std::endl;

	// Testing Key V1
	HashTbl<Account::AcctKeyV1, Account> tableV1;
	//HashTbl<Account::AcctKeyV3, Account, KeyHashV3, KeyEqualV3> tableV1;
	
	tableV1.insert(acc1.getKeyV1(), acc1);	
	tableV1.showStructure();
	tableV1.insert(acc2.getKeyV1(), acc2);	
	tableV1.showStructure();
	tableV1.insert(acc3.getKeyV1(), acc3);	
	tableV1.showStructure();
	tableV1.insert(acc4.getKeyV1(), acc4);	
	tableV1.showStructure();
	tableV1.insert(acc5.getKeyV1(), acc5);	
	tableV1.showStructure();

	Account accSearch;
	Account::AcctKeyV1 key1 = 11;
	if (tableV1.retrieve(key1, accSearch))	
		std::cout << accSearch.personName << " | " << accSearch.balance << std::endl;
	else std::cout << "Account not found!" << std::endl;
	tableV1.clear();
	
	tableV1.showStructure();

	std::cout << "----- TESTS FOR KEY VERSION 2 -----" << std::endl;
	
	// Testing Key V2
	HashTbl<Account::AcctKeyV2, Account, KeyHashV2, KeyEqualV2> tableV2;
	
	tableV2.insert(acc1.getKeyV2(), acc1);	
	tableV2.showStructure();
	tableV2.insert(acc2.getKeyV2(), acc2);	
	tableV2.showStructure();
	tableV2.insert(acc3.getKeyV2(), acc3);	
	tableV2.showStructure();
	tableV2.insert(acc4.getKeyV2(), acc4);	
	tableV2.showStructure();
	tableV2.insert(acc5.getKeyV2(), acc5);	
	tableV2.showStructure();

	Account::AcctKeyV2 key2 = std::make_pair("Maria", 11);
	if (tableV2.retrieve(key2, accSearch))	
		std::cout << accSearch.personName << " | " << accSearch.balance << std::endl;
	else std::cout << "Account not found!" << std::endl;
	tableV2.clear();
	
	tableV2.showStructure();

	std::cout << "----- TESTS FOR KEY VERSION 3 -----" << std::endl;
	
	// Testing Key V3
	HashTbl<Account::AcctKeyV3, Account, KeyHashV3, KeyEqualV3> tableV3;
	
	tableV3.insert(acc1.getKeyV3(), acc1);	
	tableV3.showStructure();
	std::cout << "Count: " << tableV3.count() << std::endl;
	tableV3.insert(acc2.getKeyV3(), acc2);	
	tableV3.showStructure();
	std::cout << "Count: " << tableV3.count() << std::endl;
	tableV3.insert(acc3.getKeyV3(), acc3);	
	tableV3.showStructure();
	std::cout << "Count: " << tableV3.count() << std::endl;
	tableV3.insert(acc4.getKeyV3(), acc4);	
	tableV3.showStructure();
	std::cout << "Count: " << tableV3.count() << std::endl;
	tableV3.insert(acc5.getKeyV3(), acc5);	
	tableV3.showStructure();
	std::cout << "Count: " << tableV3.count() << std::endl;

	Account acc6 {"Carlos", 5, 5, 5, 220.50};
	tableV3.insert(acc5.getKeyV3(), acc6);	
	tableV3.showStructure();
	std::cout << "Count: " << tableV3.count() << std::endl;

	tableV3.remove(acc1.getKeyV3());
	tableV3.showStructure();
	std::cout << "Count: " << tableV3.count() << std::endl;

	Account::AcctKeyV3 key3 = std::make_tuple("vitor", 1, 1, 1);
	if (tableV3.retrieve(key3, accSearch))	
		std::cout << accSearch.personName << " | " << accSearch.balance << std::endl;
	else std::cout << "Account not found!" << std::endl;
	tableV3.clear();
	
	tableV3.showStructure();

	return 0;
}
