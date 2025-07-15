survarium::base_match_client *__thiscall survarium::base_match_client::`vector deleting destructor'(
        survarium::base_match_client *this,
        char a2)
{
  survarium::base_match_client::~base_match_client(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
