void __thiscall Scaleform::BoolFormatter::Convert(Scaleform::BoolFormatter *this)
{
  char v1; // al

  if ( !this->IsConverted )
  {
    v1 = *((_BYTE *)this + 12);
    if ( (v1 & 2) == 0 )
    {
      if ( (v1 & 1) != 0 )
      {
        this->result.pStr = "true";
        this->result.Size = 4;
        this->IsConverted = 1;
        return;
      }
      this->result.pStr = "false";
      this->result.Size = 5;
    }
    this->IsConverted = 1;
  }
}
