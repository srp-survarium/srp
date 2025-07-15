void __usercall survarium::flash_value::SetUInt(survarium::flash_value *this@<esi>, unsigned int value@<edi>)
{
  if ( (*(_DWORD *)&this->body[4] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(survarium::flash_value *, _DWORD))(**(_DWORD **)this->body + 8))(
      this,
      *(_DWORD *)&this->body[8]);
    *(_DWORD *)this->body = 0;
  }
  *(_DWORD *)&this->body[8] = value;
  *(_DWORD *)&this->body[4] = 4;
}
