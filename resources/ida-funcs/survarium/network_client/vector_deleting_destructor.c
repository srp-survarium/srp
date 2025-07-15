survarium::network_client *__thiscall survarium::network_client::`vector deleting destructor'(
        survarium::network_client *this,
        char a2)
{
  survarium::network_client::~network_client(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
