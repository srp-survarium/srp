void __thiscall Scaleform::Render::TreeNodeArray::TreeNodeArray(
        Scaleform::Render::TreeNodeArray *this,
        const Scaleform::Render::TreeNodeArray *src)
{
  *this = *src;
  if ( ((int)src->pNodes[0] & 1) != 0 )
  {
    InterlockedExchangeAdd((volatile LONG *)(src->pData[0] & 0xFFFFFFFE), 1);
    this->pData[1] = 0;
  }
}
