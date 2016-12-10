//
//  my_singleton.hpp
//  awesomecode
//
//  Created by heyong on 2016/12/10.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef my_singleton_hpp
#define my_singleton_hpp

#include <iostream>

class CacheApi
{
public:
    static CacheApi *Instance();
    
    void notify();
    
private:
    CacheApi();
    ~CacheApi();
    CacheApi(const CacheApi &rhs);
    CacheApi &operator= (const CacheApi &ths);
    
    static CacheApi *m_pInstance;
};

#endif /* my_singleton_hpp */
