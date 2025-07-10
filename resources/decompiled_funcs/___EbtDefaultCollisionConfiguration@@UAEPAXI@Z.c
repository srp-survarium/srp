btDefaultCollisionConfiguration *__thiscall btDefaultCollisionConfiguration::`vector deleting destructor'(
        btDefaultCollisionConfiguration *this,
        char a2)
{
  btDefaultCollisionConfiguration::~btDefaultCollisionConfiguration(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
