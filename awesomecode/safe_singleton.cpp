/*
 * thread safe
 */

template <typename T>
class Singleton
{
public:
    static T& Instance()
    {
        if (m_pInstance == NULL)
        {
            Lock lock;
            if (m_pInstance == NULL)
            {
                m_pInstance = new T();
                atexit(Destroy);
            }
            return *m_pInstance;
        }
        return *m_pInstance;
    }

protected:
    Singleton();
    ~Singleton();
    
private:
    Singleton(const Singleton &rhs);
    Singleton &operator = (const Singleton &rhs);
    static T* volatile m_pInstance;

    void Destroy()
    {
        if (m_pInstance != NULL)
        {
            delete m_pInstance;
        }
        m_pInstance = NULL;
    }
};