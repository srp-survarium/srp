void __thiscall type_info::~type_info(type_info *this)
{
  this->__vftable = (type_info_vtbl *)&type_info::`vftable';
  type_info::_Type_info_dtor(this);
}
