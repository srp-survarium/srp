void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::GamePad::~GamePad(
        Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_PAD_LT; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_RT; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_HOME; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_SELECT; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_S; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_T; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_O; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_Z; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_C; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_H; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_2; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_1; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_MINUS; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_PLUS; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_LEFT; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_RIGHT; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_DOWN; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_UP; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_L2; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_R2; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_L1; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_R1; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_Y; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_X; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_B; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_A; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_START; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_BACK; // ecx
  Scaleform::GFx::AS3::Value *p_PAD_NONE; // ecx

  Flags = this->PAD_LT.Flags;
  p_PAD_LT = &this->PAD_LT;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_LT);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_LT);
  }
  p_PAD_RT = &this->PAD_RT;
  if ( (this->PAD_RT.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_RT.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_RT);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_RT);
  }
  p_PAD_HOME = &this->PAD_HOME;
  if ( (this->PAD_HOME.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_HOME.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_HOME);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_HOME);
  }
  p_PAD_SELECT = &this->PAD_SELECT;
  if ( (this->PAD_SELECT.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_SELECT.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_SELECT);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_SELECT);
  }
  p_PAD_S = &this->PAD_S;
  if ( (this->PAD_S.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_S.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_S);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_S);
  }
  p_PAD_T = &this->PAD_T;
  if ( (this->PAD_T.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_T.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_T);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_T);
  }
  p_PAD_O = &this->PAD_O;
  if ( (this->PAD_O.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_O.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_O);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_O);
  }
  p_PAD_Z = &this->PAD_Z;
  if ( (this->PAD_Z.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_Z.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_Z);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_Z);
  }
  p_PAD_C = &this->PAD_C;
  if ( (this->PAD_C.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_C.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_C);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_C);
  }
  p_PAD_H = &this->PAD_H;
  if ( (this->PAD_H.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_H.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_H);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_H);
  }
  p_PAD_2 = &this->PAD_2;
  if ( (this->PAD_2.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_2.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_2);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_2);
  }
  p_PAD_1 = &this->PAD_1;
  if ( (this->PAD_1.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_1.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_1);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_1);
  }
  p_PAD_MINUS = &this->PAD_MINUS;
  if ( (this->PAD_MINUS.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_MINUS.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_MINUS);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_MINUS);
  }
  p_PAD_PLUS = &this->PAD_PLUS;
  if ( (this->PAD_PLUS.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_PLUS.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_PLUS);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_PLUS);
  }
  p_PAD_LEFT = &this->PAD_LEFT;
  if ( (this->PAD_LEFT.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_LEFT.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_LEFT);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_LEFT);
  }
  p_PAD_RIGHT = &this->PAD_RIGHT;
  if ( (this->PAD_RIGHT.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_RIGHT.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_RIGHT);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_RIGHT);
  }
  p_PAD_DOWN = &this->PAD_DOWN;
  if ( (this->PAD_DOWN.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_DOWN.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_DOWN);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_DOWN);
  }
  p_PAD_UP = &this->PAD_UP;
  if ( (this->PAD_UP.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_UP.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_UP);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_UP);
  }
  p_PAD_L2 = &this->PAD_L2;
  if ( (this->PAD_L2.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_L2.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_L2);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_L2);
  }
  p_PAD_R2 = &this->PAD_R2;
  if ( (this->PAD_R2.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_R2.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_R2);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_R2);
  }
  p_PAD_L1 = &this->PAD_L1;
  if ( (this->PAD_L1.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_L1.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_L1);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_L1);
  }
  p_PAD_R1 = &this->PAD_R1;
  if ( (this->PAD_R1.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_R1.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_R1);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_R1);
  }
  p_PAD_Y = &this->PAD_Y;
  if ( (this->PAD_Y.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_Y.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_Y);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_Y);
  }
  p_PAD_X = &this->PAD_X;
  if ( (this->PAD_X.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_X.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_X);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_X);
  }
  p_PAD_B = &this->PAD_B;
  if ( (this->PAD_B.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_B.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_B);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_B);
  }
  p_PAD_A = &this->PAD_A;
  if ( (this->PAD_A.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_A.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_A);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_A);
  }
  p_PAD_START = &this->PAD_START;
  if ( (this->PAD_START.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_START.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_START);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_START);
  }
  p_PAD_BACK = &this->PAD_BACK;
  if ( (this->PAD_BACK.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_BACK.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_BACK);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_BACK);
  }
  p_PAD_NONE = &this->PAD_NONE;
  if ( (this->PAD_NONE.Flags & 0x1F) > 9 )
  {
    if ( (this->PAD_NONE.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_PAD_NONE);
      Scaleform::GFx::AS3::Class::~Class(this);
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_PAD_NONE);
  }
  Scaleform::GFx::AS3::Class::~Class(this);
}
