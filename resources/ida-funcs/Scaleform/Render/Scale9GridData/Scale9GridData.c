void __thiscall Scaleform::Render::Scale9GridData::Scale9GridData(
        Scaleform::Render::Scale9GridData *this,
        const Scaleform::Render::Scale9GridData *__that)
{
  float x2; // [esp+0h] [ebp-8h]
  float v5; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float v7; // [esp+4h] [ebp-4h]
  float y1; // [esp+Ch] [ebp+4h]
  float v9; // [esp+Ch] [ebp+4h]

  this->__vftable = (Scaleform::Render::Scale9GridData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = __that->RefCount;
  this->__vftable = (Scaleform::Render::Scale9GridData_vtbl *)&Scaleform::Render::Matrix4x4Ref<float>::`vftable';
  y1 = __that->S9Rect.y1;
  x2 = __that->S9Rect.x2;
  y2 = __that->S9Rect.y2;
  this->S9Rect.x1 = __that->S9Rect.x1;
  this->S9Rect.y1 = y1;
  this->S9Rect.x2 = x2;
  this->S9Rect.y2 = y2;
  v9 = __that->Bounds.y1;
  v7 = __that->Bounds.x2;
  v5 = __that->Bounds.y2;
  this->Bounds.x1 = __that->Bounds.x1;
  this->Bounds.y1 = v9;
  this->Bounds.x2 = v7;
  this->Bounds.y2 = v5;
  this->ShapeMtx = __that->ShapeMtx;
  this->Scale9Mtx = __that->Scale9Mtx;
  this->ViewMtx = __that->ViewMtx;
}
