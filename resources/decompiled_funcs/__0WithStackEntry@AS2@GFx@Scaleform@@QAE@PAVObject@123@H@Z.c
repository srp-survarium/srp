void __thiscall Scaleform::GFx::AS2::WithStackEntry::WithStackEntry(
        Scaleform::GFx::AS2::WithStackEntry *this,
        Scaleform::GFx::AS2::Object *pobj,
        int end)
{
  this->pObject = pobj;
  if ( pobj )
    pobj->RefCount = (pobj->RefCount + 1) & 0x8FFFFFFF;
  this->BlockEndPc = end | 0x80000000;
}
