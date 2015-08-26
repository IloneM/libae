#ifndef LAYERED_EXCEPTION_H
#define LAYERED_EXCEPTION_H

#include <string>
#include <exception>
#include <list>

#include <ostream>
#include <sstream>

/**
 * @TODO make it with a stack
 * @TODO make it with a template
 * @TODO add operator <<  and >>
 * @TODO add endl parser before adding string
 */

namespace Exception {

template<class Detail>
class Layered : public virtual std::exception {
		
protected:
	/**
	 * @brief the exception message wich will be augmented by the successives layers
	 */
	std::list<Detail> _details;

public:
	Layered();
	Layered(Detail& detail);
//	Layered(char* details) : _details(details) {}

	virtual const char* what() const throw();

	Layered<Detail>& append(const Detail& detailToAppend);

	inline std::list<Detail> details() {
		return _details;
	}
/*
	char* append(char* detailsToAppend) {
		_details += detailsToAppend;
		return _details.data();
	}
*/
	//Layered<Detail>& operator<<(Layered<Detail>& ex, const Detail& detailToAppend);

	//friend std::ostream& operator<< <>(std::ostream& out, const Layered<Detail>& ex);
};

template<class Detail>
std::ostream& operator<<(std::ostream& out, const Layered<Detail>& ex);

}

#endif
