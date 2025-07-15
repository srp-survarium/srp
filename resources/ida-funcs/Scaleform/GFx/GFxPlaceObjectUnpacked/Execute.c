void __thiscall Scaleform::GFx::GFxPlaceObjectUnpacked::Execute(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer *v2; // esi
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v5; // eax

  v2 = m;
  StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(m);
  m = (Scaleform::GFx::DisplayObjContainer *)&StringManager->EmptyStringNode;
  ++StringManager->EmptyStringNode.RefCount;
  v2->AddDisplayObject(v2, &this->Pos, (const Scaleform::GFx::ASString *)&m, 0, 0, -1u, 4u, 0, 0);
  v5 = (Scaleform::GFx::ASStringNode *)m;
  --m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
