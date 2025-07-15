void __thiscall Scaleform::Render::TextMeshProvider::AddNotifier(
        Scaleform::Render::TextMeshProvider *this,
        const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *notifier)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_Notifiers; // edi
  unsigned int v4; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax

  if ( notifier )
  {
    pHeap = this->Notifiers.Data.pHeap;
    p_Notifiers = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&this->Notifiers;
    v4 = this->Notifiers.Data.Size + 1;
    if ( v4 >= this->Notifiers.Data.Size )
    {
      if ( v4 >= this->Notifiers.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Notifiers,
          pHeap,
          v4 + (v4 >> 2));
    }
    else if ( v4 < this->Notifiers.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Notifiers,
        pHeap,
        v4);
    }
    Data = p_Notifiers->Data;
    p_Notifiers->Size = v4;
    Data[v4 - 1] = notifier;
    Scaleform::Render::GlyphQueue::PinSlot((Scaleform::Render::GlyphSlot *)notifier[3].pObject);
  }
}
