void __thiscall Scaleform::GFx::AS2::WithStackEntry::WithStackEntry(
        Scaleform::GFx::AS2::WithStackEntry *this,
        Scaleform::GFx::InteractiveObject *pcharacter,
        unsigned int end)
{
  this->pObject = (Scaleform::GFx::AS2::Object *)pcharacter;
  if ( pcharacter )
    ++pcharacter->RefCount;
  this->BlockEndPc = end;
}


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
