unsigned int __thiscall Scaleform::StringBuffer::GetLength(Scaleform::StringBuffer *this)
{
  unsigned int result; // eax

  result = this->Size;
  if ( !this->LengthIsSize )
  {
    result = Scaleform::UTF8Util::GetLength(this->pData, this->Size);
    if ( result == this->Size )
      this->LengthIsSize = 1;
  }
  return result;
}
