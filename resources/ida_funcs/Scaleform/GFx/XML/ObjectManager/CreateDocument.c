void __thiscall Scaleform::GFx::XML::ObjectManager::CreateDocument(Scaleform::GFx::XML::ObjectManager *this)
{
  Scaleform::GFx::XML::Document *v2; // eax

  v2 = (Scaleform::GFx::XML::Document *)this->pHeap->Alloc(this->pHeap, 72, 0);
  if ( v2 )
    Scaleform::GFx::XML::Document::Document(v2, this);
}
