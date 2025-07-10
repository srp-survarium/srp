char __thiscall Scaleform::GFx::Stream::ReadStringWithLength(Scaleform::GFx::Stream *this, Scaleform::String *pstr)
{
  signed int v3; // eax
  unsigned int Pos; // eax
  unsigned __int8 v5; // cl
  Scaleform::GFx::Stream::ReadStringWithLength::__l2::StringReader sreader; // [esp+4h] [ebp-8h] BYREF

  v3 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v3 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  Pos = this->Pos;
  v5 = this->pBuffer[Pos];
  this->Pos = Pos + 1;
  if ( v5 )
  {
    sreader.__vftable = (Scaleform::GFx::Stream::ReadStringWithLength::__l2::StringReader_vtbl *)&`Scaleform::GFx::Stream::ReadStringWithLength'::`2'::StringReader::`vftable';
    sreader.pStream = this;
    Scaleform::String::AssignString(pstr, &sreader, v5);
    return 1;
  }
  else
  {
    Scaleform::String::Clear(pstr);
    return 0;
  }
}
