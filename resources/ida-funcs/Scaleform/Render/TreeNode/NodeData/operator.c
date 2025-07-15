Scaleform::Render::TreeNode::NodeData *__thiscall Scaleform::Render::TreeNode::NodeData::operator=(
        Scaleform::Render::TreeNode::NodeData *this,
        const Scaleform::Render::TreeNode::NodeData *__that)
{
  Scaleform::Render::TreeNode::NodeData *result; // eax
  float x2; // [esp+10h] [ebp-8h]
  float v6; // [esp+10h] [ebp-8h]
  float y2; // [esp+14h] [ebp-4h]
  float v8; // [esp+14h] [ebp-4h]
  float y1; // [esp+1Ch] [ebp+4h]
  float v10; // [esp+1Ch] [ebp+4h]

  this->Type = __that->Type;
  this->Flags = __that->Flags;
  memcpy((int)&this->M34, (const __m128i *)&__that->M34, sizeof(this->M34));
  if ( this->States.ArraySize | __that->States.ArraySize )
    Scaleform::Render::StateData::assignBag(&this->States, &__that->States);
  qmemcpy(&this->Cx, &__that->Cx, sizeof(this->Cx));
  y1 = __that->AproxLocalBounds.y1;
  x2 = __that->AproxLocalBounds.x2;
  y2 = __that->AproxLocalBounds.y2;
  this->AproxLocalBounds.x1 = __that->AproxLocalBounds.x1;
  this->AproxLocalBounds.y1 = y1;
  this->AproxLocalBounds.x2 = x2;
  this->AproxLocalBounds.y2 = y2;
  result = this;
  v10 = __that->AproxParentBounds.y1;
  v8 = __that->AproxParentBounds.x2;
  v6 = __that->AproxParentBounds.y2;
  this->AproxParentBounds.x1 = __that->AproxParentBounds.x1;
  this->AproxParentBounds.y1 = v10;
  this->AproxParentBounds.x2 = v8;
  this->AproxParentBounds.y2 = v6;
  return result;
}
