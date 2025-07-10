void __thiscall survarium::flash_value::~flash_value(survarium::flash_value *this)
{
  if ( (*(_DWORD *)&this->body[4] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(survarium::flash_value *, _DWORD))(**(_DWORD **)this->body + 8))(
      this,
      *(_DWORD *)&this->body[8]);
    *(_DWORD *)this->body = 0;
  }
  *(_DWORD *)&this->body[4] = 0;
}
