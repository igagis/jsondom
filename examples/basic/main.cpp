#include <iostream>
#include <cassert>

#include <jsondom/dom.hpp>

const char* json = "{\"key1\": \"value1\", \"key2\": \"value2\"}";

int main(int c, const char** v){
	auto dom = jsondom::read(json);

	if(!dom.is_object()){
		std::cout << "parsed JSON document root node is unexpectedly not an object" << std::endl;
		assert(false);
	}

	// let's check if there is an expected key1-value1 pair,
	// but do not fail if there is no such key or value is not of an expected type

	auto value1_i = dom.object().find("key1");
	if(value1_i != dom.object().end()){
		auto& value1 = value1_i->second;
		if(value1.is_string()){
			std::cout << "value1 = " << value1.string() << std::endl;
		}else{
			// this never happens in this example, but just to show how
			// to handle cases when JSON value type is not as expected
			std::cout << "value1 is not a string" << std::endl;
		}
	}else{
		// this never happens in this example, but just to show how
		// to handle cases when JSON key is not found
		std::cout << "key1 is not found" << std::endl;
	}

	// Try to use key2-value2 pair, relying on that it exists.
	// An exception will be thrown if something goes wrong, like
	// no 'key2' key is found or value is of unexpected type.

	try{
		std::cout << "value2 = " << dom.object().at("key2").string() << std::endl;
	}catch(std::logic_error& e){
		// handle exception here if needed
		std::cout << e.what() << std::endl;
		throw;
	}

	return 0;
}