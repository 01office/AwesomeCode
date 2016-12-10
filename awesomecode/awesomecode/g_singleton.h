//
//  g_singleton.h
//  awesomecode
//
//  Created by heyong on 2016/12/10.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef g_singleton_h
#define g_singleton_h

#define DECLARE_SINGLETON(CLASS)\
public:\
    static CLASS *Instance();\
private:\
    CLASS();\
    ~CLASS();\
    CLASS(const CLASS &);\
    CLASS &operator= (const CLASS &);\
    static CLASS *m_pInstance;

#define IMPLEMENT_SINGLETON(CLASS)\
    CLASS *CLASS::m_pInstance = NULL;\
    \
    CLASS *CLASS::Instance()\
    {\
        if (m_pInstance == NULL) {\
            m_pInstance = new CLASS;\
        }\
        return m_pInstance;\
    }

#endif /* g_singleton_h */
