void __thiscall vostok::configs::binary_config_value::fix_up(
        vostok::configs::binary_config_value *this,
        unsigned int offset)
{
  int v3; // ebx
  int type; // eax
  int count; // ebp

  v3 = 0;
  if ( this->id.pointer )
    this->id.pointer += offset;
  type = this->type;
  if ( (unsigned int)type > 2 )
  {
    this->data.pointer = (char *)this->data.pointer + offset;
    if ( type <= 4 )
    {
      if ( this->count )
      {
        count = this->count;
        do
        {
          vostok::configs::binary_config_value::fix_up(
            (vostok::configs::binary_config_value *)((char *)this->data.pointer + v3),
            offset);
          v3 += 24;
          --count;
        }
        while ( count );
      }
    }
  }
}
