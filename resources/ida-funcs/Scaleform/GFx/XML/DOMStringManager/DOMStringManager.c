void __thiscall Scaleform::GFx::XML::DOMStringManager::DOMStringManager(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringNode *key; // [esp+8h] [ebp-4h] BYREF

  this->StringSet.pTable = 0;
  this->pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->pStringNodePages = 0;
  this->pFreeStringNodes = 0;
  this->pFreeTextBuffers = 0;
  this->pTextBufferPages = 0;
  this->EmptyStringNode.RefCount = 1;
  this->EmptyStringNode.Size = 0;
  this->EmptyStringNode.HashFlags = (unsigned int)&vostok::memory::s_CRT_arena[5574199]
                                  & Scaleform::String::BernsteinHashFunction((char *)&buf, 0, 0x1505u);
  this->EmptyStringNode.pData = (const char *)&buf;
  this->EmptyStringNode.pManager = this;
  key = &this->EmptyStringNode;
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::add<Scaleform::GFx::XML::DOMStringNode *>(
    &this->StringSet,
    this,
    &key,
    this->EmptyStringNode.HashFlags);
}
