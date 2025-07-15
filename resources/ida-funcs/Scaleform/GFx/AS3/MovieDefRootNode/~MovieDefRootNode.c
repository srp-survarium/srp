void __thiscall Scaleform::GFx::AS3::MovieDefRootNode::~MovieDefRootNode(Scaleform::GFx::AS3::MovieDefRootNode *this)
{
  signed int v2; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *Data; // eax
  Scaleform::GFx::AS3::VMAbcFile *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v5; // edi
  unsigned int RefCount; // eax
  Scaleform::RefCountVImpl *v7; // ecx

  v2 = this->AbcFiles.Data.Size - 1;
  for ( this->__vftable = (Scaleform::GFx::AS3::MovieDefRootNode_vtbl *)&Scaleform::GFx::AS3::MovieDefRootNode::`vftable';
        v2 >= 0;
        --v2 )
  {
    Data = this->AbcFiles.Data.Data;
    pObject = Data[v2].pObject;
    v5 = &Data[v2];
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v5->pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      v5->pObject = 0;
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    this->AbcFiles.Data.Data,
    this->AbcFiles.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->AbcFiles.Data.Data);
  this->__vftable = (Scaleform::GFx::AS3::MovieDefRootNode_vtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable';
  v7 = (Scaleform::RefCountVImpl *)this->pFontManager.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
}
