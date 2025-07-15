void __thiscall Scaleform::GFx::ASStringManager::ASStringManager(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::HashSetUncachedLH<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,324> *p_StringSet; // ebx
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::ASStringNode *pLower; // ecx
  unsigned int RefCount; // edx
  unsigned int v7; // ecx
  unsigned int Size; // edx
  unsigned int HashFlags; // [esp-4h] [ebp-14h]
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // [esp+Ch] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::ASStringManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::ASStringManager_vtbl *)&Scaleform::GFx::ASStringManager::`vftable';
  p_StringSet = &this->StringSet;
  this->StringSet.pTable = 0;
  this->pHeap = pheap;
  this->pLog.pObject = 0;
  Scaleform::StringLH::StringLH(&this->FileName);
  this->pStringNodePages = 0;
  this->pFreeStringNodes = 0;
  this->pFreeTextBuffers = 0;
  this->pTextBufferPages = 0;
  this->EmptyStringNode.RefCount = 1;
  this->EmptyStringNode.Size = 0;
  this->EmptyStringNode.HashFlags = Scaleform::String::BernsteinHashFunctionCIS((char *)uri, 0, 0x1505u) & 0xFFFFFF
                                  | 0xC8000000;
  this->EmptyStringNode.pData = uri;
  this->EmptyStringNode.pManager = this;
  this->EmptyStringNode.pLower = &this->EmptyStringNode;
  HashFlags = this->EmptyStringNode.HashFlags;
  p_EmptyStringNode = &this->EmptyStringNode;
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
    p_StringSet,
    p_StringSet,
    &p_EmptyStringNode,
    HashFlags);
  pManager = this->EmptyStringNode.pManager;
  this->NullStringNode.pData = this->EmptyStringNode.pData;
  pLower = this->EmptyStringNode.pLower;
  this->NullStringNode.pManager = pManager;
  RefCount = this->EmptyStringNode.RefCount;
  this->NullStringNode.pLower = pLower;
  v7 = this->EmptyStringNode.HashFlags;
  this->NullStringNode.RefCount = RefCount;
  Size = this->EmptyStringNode.Size;
  this->NullStringNode.HashFlags = v7;
  this->NullStringNode.Size = Size;
  this->NullStringNode.pLower = &this->NullStringNode;
}
