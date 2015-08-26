#include "layered.h"

namespace Exception {

	template<class Detail>
	Layered<Detail>::Layered() : _details() {}

	template<class Detail>
	Layered<Detail>::Layered(Detail& detail) {
		_details.push_back(detail);
	}
//	Layered(char* details) : _details(details) {}

	template<class Detail>
	const char* Layered<Detail>::what() const throw() {
		std::ostringstream stream;
		stream << *this;
		return stream.str().data();
	}

	template<class Detail>
	Layered<Detail>& Layered<Detail>::append(const Detail& detailToAppend) {
		_details.push_back(detailToAppend);
		return *this;
	}

/*
	template<class Detail>
	std::list<Detail> Layered<Detail>::details() {
		return _details;
	}

	char* append(char* detailsToAppend) {
		_details += detailsToAppend;
		return _details.data();
	}

	template<class Detail>
	Layered<Detail>& Layered<Detail>::operator<<(Layered<Detail>& ex, const Detail& detailToAppend) {
		return ex.append(detailToAppend);
	}
*/
	template<class Detail>
	std::ostream& operator<<(std::ostream& out, const Layered<Detail>& ex) {
		for(typename std::list<Detail>::iterator it=ex.details().begin(); it!= ex.details().end(); it++) {
			out << it << '\n';
		}
		return out;
	}	
}

