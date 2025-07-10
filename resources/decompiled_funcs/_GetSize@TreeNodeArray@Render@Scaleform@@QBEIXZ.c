int __thiscall Scaleform::Render::TreeNodeArray::GetSize(Scaleform::Render::TreeNodeArray *this)
{
  int result; // eax

  result = this->pData[0];
  if ( this->pData[0] )
  {
    if ( (result & 1) != 0 )
      return *(_DWORD *)((result & 0xFFFFFFFE) + 4);
    else
      return (this->pData[1] != 0) + 1;
  }
  return result;
}
