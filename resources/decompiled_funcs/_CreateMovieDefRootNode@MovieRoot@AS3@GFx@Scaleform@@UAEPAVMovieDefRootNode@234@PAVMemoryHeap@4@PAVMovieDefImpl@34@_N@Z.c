Scaleform::GFx::AS3::MovieDefRootNode *__thiscall Scaleform::GFx::AS3::MovieRoot::CreateMovieDefRootNode(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        bool importFlag)
{
  Scaleform::GFx::AS3::MovieDefRootNode *result; // eax

  result = (Scaleform::GFx::AS3::MovieDefRootNode *)pheap->Alloc(pheap, 48, 0);
  if ( !result )
    return 0;
  result->SpriteRefCount = 1;
  result->pDefImpl = pdefImpl;
  result->ImportFlag = importFlag;
  result->pFontManager.pObject = 0;
  result->__vftable = (Scaleform::GFx::AS3::MovieDefRootNode_vtbl *)&Scaleform::GFx::AS3::MovieDefRootNode::`vftable';
  result->AbcFiles.Data.Data = 0;
  result->AbcFiles.Data.Size = 0;
  result->AbcFiles.Data.Policy.Capacity = 0;
  return result;
}
