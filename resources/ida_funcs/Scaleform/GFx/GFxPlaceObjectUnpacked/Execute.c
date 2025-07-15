void __thiscall Scaleform::GFx::GFxPlaceObjectUnpacked::Execute(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::ASStringNode *m)
{
  Scaleform::GFx::DisplayObjContainer *v2; // esi
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v5; // eax

  v2 = (Scaleform::GFx::DisplayObjContainer *)m;
  StringManager = Scaleform::GFx::InteractiveObject::GetStringManager((Scaleform::GFx::InteractiveObject *)m);
  m = &StringManager->EmptyStringNode;
  ++StringManager->EmptyStringNode.RefCount;
  v2->AddDisplayObject(v2, &this->Pos, (const Scaleform::GFx::ASString *)&m, 0, 0, -1u, 4u, 0, 0);
  v5 = m;
  --m->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
