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
