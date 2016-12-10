//
//  my_singleton.cpp
//  awesomecode
//
//  Created by heyong on 2016/12/10.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include "my_singleton.hpp"

CacheApi::CacheApi(){}
CacheApi::~CacheApi(){}

CacheApi *CacheApi::m_pInstance = NULL;
CacheApi *CacheApi::Instance()
{
    if (m_pInstance == NULL) {
        m_pInstance = new CacheApi;
    }
    return m_pInstance;
}

void CacheApi::notify()
{
    std::cout << "Hello, singleton" << std::endl;
}

// use macro
IMPLEMENT_SINGLETON(GApi)
GApi::GApi(){}
GApi::~GApi(){}
void GApi::notify()
{
    std::cout << "Use Macro" << std::endl;
}
