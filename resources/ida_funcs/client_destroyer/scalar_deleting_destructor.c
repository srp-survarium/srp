client_destroyer *__thiscall client_destroyer::`scalar deleting destructor'(client_destroyer *this, char a2)
{
  client_destroyer::~client_destroyer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
