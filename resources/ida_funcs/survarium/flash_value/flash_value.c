void __thiscall survarium::flash_value::flash_value(survarium::flash_value *this)
{
  if ( this )
  {
    *(_DWORD *)this->body = 0;
    *(_DWORD *)&this->body[4] = 0;
  }
}
