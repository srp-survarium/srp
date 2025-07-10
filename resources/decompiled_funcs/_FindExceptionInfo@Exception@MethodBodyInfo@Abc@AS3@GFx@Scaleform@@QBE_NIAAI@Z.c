char __thiscall Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception::FindExceptionInfo(
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *this,
        unsigned int offset,
        unsigned int *handler_num)
{
  unsigned int Size; // ebx
  unsigned int v4; // eax

  Size = this->info.Data.Size;
  if ( *handler_num >= Size )
    return 0;
  while ( offset < this->info.Data.Data[*handler_num].from || offset > this->info.Data.Data[*handler_num].to )
  {
    v4 = *handler_num + 1;
    *handler_num = v4;
    if ( v4 >= Size )
      return 0;
  }
  return 1;
}
