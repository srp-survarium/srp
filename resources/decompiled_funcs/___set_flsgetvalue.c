void *__set_flsgetvalue()
{
  void *Value; // esi

  Value = TlsGetValue(__getvalueindex);
  if ( !Value )
  {
    Value = _decode_pointer(gpFlsGetValue);
    TlsSetValue(__getvalueindex, Value);
  }
  return Value;
}
