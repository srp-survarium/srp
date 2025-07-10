Scaleform::GFx::MovieDefRootNode *__thiscall Scaleform::GFx::AS2::MovieRoot::CreateMovieDefRootNode(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        bool importFlag)
{
  Scaleform::GFx::MovieDefRootNode *result; // eax

  result = (Scaleform::GFx::MovieDefRootNode *)pheap->Alloc(pheap, 36, 0);
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::MovieDefRootNode_vtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable';
  result->SpriteRefCount = 1;
  result->pDefImpl = pdefImpl;
  result->ImportFlag = importFlag;
  result->pFontManager.pObject = 0;
  return result;
}
