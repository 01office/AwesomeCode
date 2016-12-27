//
//  common_def.h
//  awesomecode
//
//  Created by heyong on 2016/12/20.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef common_def_h
#define common_def_h

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


///
#define DECL_SIMP_FIELD(Type, Attr)\
public:\
    Type *m_##Attr;\
public:\
    void set_##Attr(const Type& value)\
    {\
        m_##Attr = value;\
    }\
    const Type& get() const\
    {\
        return m_##Attr;\
    }


inline bool compare1(int a, int b)
{
    return a > b;
}

class compare2
{
public:
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};

#endif /* common_def_h */
