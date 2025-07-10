void __thiscall Scaleform::GFx::RemoveObjectTag::Execute(
        Scaleform::GFx::RemoveObjectTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(m, this->Depth, (Scaleform::GFx::ResourceId)this->Id);
}
