survarium::items_dictionary *__thiscall survarium::items_dictionary::`vector deleting destructor'(
        survarium::items_dictionary *this,
        char a2)
{
  survarium::items_dictionary::~items_dictionary(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
