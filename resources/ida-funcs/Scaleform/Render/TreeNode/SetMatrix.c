void __thiscall Scaleform::Render::TreeNode::SetMatrix(
        Scaleform::Render::TreeNode *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::ContextImpl::EntryData *v3; // eax

  v3 = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 1u) + 2;
  *(float *)&v3->__vftable = m->M[0][0];
  *(float *)&v3->Type = m->M[0][1];
  v3[1] = *(Scaleform::Render::ContextImpl::EntryData *)&m->M[0][2];
  v3[2] = *(Scaleform::Render::ContextImpl::EntryData *)&m->M[1][0];
  v3[3] = *(Scaleform::Render::ContextImpl::EntryData *)&m->M[1][2];
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
