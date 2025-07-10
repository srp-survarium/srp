void __thiscall Scaleform::GFx::RemoveObject2Tag::Execute(
        Scaleform::GFx::RemoveObject2Tag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(m, this->Depth, (Scaleform::GFx::ResourceId)0x40000);
}
