void __thiscall Scaleform::StringBuffer::operator=(Scaleform::StringBuffer *this, char *pstr)
{
  char *v2; // edi
  unsigned int v4; // esi

  v2 = pstr;
  if ( !pstr )
    v2 = (char *)&buf;
  v4 = strlen(v2);
  Scaleform::StringBuffer::Resize(this, v4);
  memcpy((unsigned __int8 *)this->pData, (unsigned __int8 *)v2, v4);
}
