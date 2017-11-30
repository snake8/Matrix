//
//  TypesCheck.h
//  Matrix
//
//  Created by Daniel Solovich on 9/24/17.
//  Copyright © 2017 Daniel Solovich. All rights reserved.
//

#ifndef TypesCheck_h
#define TypesCheck_h

template<typename T>
struct IsTypeChar {
    static const bool value = false;
};
template<> struct IsTypeChar<char> {
    static const bool value = true;
};

template<typename T>
struct IsTypeString {
    static const bool value = false;
};
template<> struct IsTypeString<std::string> {
    static const bool value = true;
};

#endif /* TypesCheck_h */
