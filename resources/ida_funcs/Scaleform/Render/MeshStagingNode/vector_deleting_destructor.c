Scaleform::Render::MeshStagingNode *__thiscall Scaleform::Render::MeshStagingNode::`vector deleting destructor'(
        Scaleform::Render::MeshStagingNode *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::MeshStagingNode::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
