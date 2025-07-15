int __thiscall Scaleform::GFx::MovieImpl::HandleEvent(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::Event *event)
{
  int v4; // eax
  Scaleform::GFx::Event::EventType Type; // eax
  const Scaleform::GFx::Event *v6; // edi
  int v7; // ebp
  Scaleform::GFx::KeyboardState *v8; // esi
  Scaleform::GFx::State *v9; // eax
  Scaleform::RefCountVImpl *v10; // esi
  unsigned int States; // eax
  unsigned int v12; // eax
  Scaleform::GFx::KeyboardState *v13; // edi
  unsigned __int8 v14; // al
  Scaleform::GFx::Event::EventType v15; // edi
  Scaleform::GFx::Event::EventType v16; // edi
  Scaleform::GFx::Event::EventType v17; // edi
  Scaleform::GFx::Event::EventType v18; // edi
  Scaleform::GFx::KeyboardState *KeyboardState; // edi
  Scaleform::GFx::Event::EventType v20; // eax
  Scaleform::GFx::KeyboardState *v21; // edi
  Scaleform::RefCountVImpl *v22; // edi
  int v23; // esi
  Scaleform::Render::Point<float> p; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Render::Point<float> result; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::KeyboardState *KeyboardStates; // [esp+24h] [ebp+4h]

  if ( !this->IsMovieFocused(this) )
  {
    if ( event->Type != SetFocus )
      return 0;
    goto LABEL_5;
  }
  Type = event->Type;
  if ( event->Type == SetFocus )
  {
LABEL_5:
    v6 = event + 1;
    KeyboardStates = this->KeyboardStates;
    v7 = -8 - (_DWORD)event;
    do
    {
      if ( LOBYTE(v6->Type) )
      {
        v8 = (unsigned int)v6 + v7 < 6 ? KeyboardStates : 0;
        Scaleform::GFx::KeyboardState::SetKeyToggled(v8, 144, (v6->Type & 0x10) != 0);
        Scaleform::GFx::KeyboardState::SetKeyToggled(v8, 20, (v6->Type & 8) != 0);
        Scaleform::GFx::KeyboardState::SetKeyToggled(v8, 145, (v6->Type & 0x20) != 0);
      }
      ++KeyboardStates;
      v6 = (const Scaleform::GFx::Event *)((char *)v6 + 1);
    }
    while ( (unsigned int)v6 + v7 < 6 );
    this->Flags |= 0x40000u;
    v9 = this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
    v10 = (Scaleform::RefCountVImpl *)v9;
    if ( v9 )
      ((void (__thiscall *)(Scaleform::GFx::State *, Scaleform::GFx::MovieImpl *))v9->__vftable[29].~Scaleform::GFx::State)(
        v9,
        this);
    this->pASMovieRoot.pObject->OnMovieFocus(this->pASMovieRoot.pObject, 1);
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    return 1;
  }
  if ( Type == KeyDown || Type == KeyUp )
  {
    States = event[2].Modifiers.States;
    if ( States < 6 )
    {
      v12 = States;
      v13 = &this->KeyboardStates[v12];
      if ( (Scaleform::GFx::MovieImpl *)((char *)this + v12 * 1660) != (Scaleform::GFx::MovieImpl *)-4936 )
      {
        v14 = event->Modifiers.States;
        if ( v14 )
        {
          Scaleform::GFx::KeyboardState::SetKeyToggled(v13, 144, (v14 & 0x10) != 0);
          Scaleform::GFx::KeyboardState::SetKeyToggled(v13, 20, (event->Modifiers.States & 8) != 0);
          Scaleform::GFx::KeyboardState::SetKeyToggled(v13, 145, (event->Modifiers.States & 0x20) != 0);
        }
      }
    }
  }
  switch ( event->Type )
  {
    case MouseMove:
      v15 = event[3].Type;
      if ( v15 >= this->MouseCursorCount )
        goto LABEL_65;
      p.x = *(float *)&event[1].Type;
      p.y = *(float *)&event[1].Modifiers.States;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
      Scaleform::GFx::InputEventsQueue::AddMouseMove(&this->InputEventsQueue, v15, &result);
      return 3;
    case MouseDown:
      v17 = event[3].Type;
      if ( v17 >= this->MouseCursorCount )
        goto LABEL_65;
      p.x = *(float *)&event[1].Type;
      p.y = *(float *)&event[1].Modifiers.States;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
      Scaleform::GFx::InputEventsQueue::AddMouseButtonEvent(
        &this->InputEventsQueue,
        v17,
        &result,
        1 << *(_DWORD *)&event[2].Modifiers.States,
        0);
      goto LABEL_25;
    case MouseUp:
      v16 = event[3].Type;
      if ( v16 >= this->MouseCursorCount )
        goto LABEL_65;
      p.x = *(float *)&event[1].Type;
      p.y = *(float *)&event[1].Modifiers.States;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
      Scaleform::GFx::InputEventsQueue::AddMouseButtonEvent(
        &this->InputEventsQueue,
        v16,
        &result,
        1 << *(_DWORD *)&event[2].Modifiers.States,
        0x80u);
LABEL_25:
      v4 = 3;
      break;
    case MouseWheel:
      v18 = event[3].Type;
      if ( v18 >= this->MouseCursorCount )
        goto LABEL_65;
      p.x = *(float *)&event[1].Type;
      p.y = *(float *)&event[1].Modifiers.States;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
      Scaleform::GFx::InputEventsQueue::AddMouseWheel(
        &this->InputEventsQueue,
        v18,
        &result,
        (int)*(float *)&event[2].Type);
      v4 = 3;
      break;
    case KeyDown:
      KeyboardState = Scaleform::GFx::MovieImpl::GetKeyboardState(this, event[2].Modifiers.States);
      if ( KeyboardState )
      {
        Scaleform::GFx::KeyboardState::SetKeyDown(
          KeyboardState,
          event[1].Type,
          event[1].Modifiers.States,
          event->Modifiers,
          1);
        switch ( event[1].Type )
        {
          case GestureEnd:
            if ( (event->Modifiers.States & 0x40) != 0 )
              Scaleform::GFx::KeyboardState::SetKeyDown(KeyboardState, 161, 0, (Scaleform::KeyModifiers)0x80, 0);
            else
              Scaleform::GFx::KeyboardState::SetKeyDown(KeyboardState, 160, 0, (Scaleform::KeyModifiers)0x80, 0);
            break;
          case GestureSimple:
            if ( (event->Modifiers.States & 0x40) != 0 )
              Scaleform::GFx::KeyboardState::SetKeyDown(KeyboardState, 163, 0, (Scaleform::KeyModifiers)0x80, 0);
            else
              Scaleform::GFx::KeyboardState::SetKeyDown(KeyboardState, 162, 0, (Scaleform::KeyModifiers)0x80, 0);
            break;
          case GamePadAnalog:
            if ( (event->Modifiers.States & 0x40) != 0 )
              Scaleform::GFx::KeyboardState::SetKeyDown(KeyboardState, 165, 0, (Scaleform::KeyModifiers)0x80, 0);
            else
              Scaleform::GFx::KeyboardState::SetKeyDown(KeyboardState, 164, 0, (Scaleform::KeyModifiers)0x80, 0);
            break;
        }
      }
      Scaleform::GFx::InputEventsQueue::AddKeyDown(
        &this->InputEventsQueue,
        SLOWORD(event[1].Type),
        event[1].Modifiers.States,
        event->Modifiers,
        event[2].Modifiers.States);
      v20 = event[2].Type;
      if ( v20 != TouchTap && ((unsigned int)v20 < 0x20 || v20 == (IME|MouseWheel|0x60)) )
        goto LABEL_25;
      Scaleform::GFx::InputEventsQueue::AddCharTyped(&this->InputEventsQueue, v20, event[2].Modifiers.States);
      v4 = 3;
      break;
    case KeyUp:
      v21 = Scaleform::GFx::MovieImpl::GetKeyboardState(this, event[2].Modifiers.States);
      if ( v21 )
      {
        Scaleform::GFx::KeyboardState::SetKeyUp(v21, event[1].Type, event[1].Modifiers.States, event->Modifiers, 1);
        switch ( event[1].Type )
        {
          case GestureEnd:
            if ( (event->Modifiers.States & 0x40) != 0 )
              Scaleform::GFx::KeyboardState::SetKeyUp(v21, 161, 0, (Scaleform::KeyModifiers)0x80, 0);
            else
              Scaleform::GFx::KeyboardState::SetKeyUp(v21, 160, 0, (Scaleform::KeyModifiers)0x80, 0);
            break;
          case GestureSimple:
            if ( (event->Modifiers.States & 0x40) != 0 )
              Scaleform::GFx::KeyboardState::SetKeyUp(v21, 163, 0, (Scaleform::KeyModifiers)0x80, 0);
            else
              Scaleform::GFx::KeyboardState::SetKeyUp(v21, 162, 0, (Scaleform::KeyModifiers)0x80, 0);
            break;
          case GamePadAnalog:
            if ( (event->Modifiers.States & 0x40) != 0 )
              Scaleform::GFx::KeyboardState::SetKeyUp(v21, 165, 0, (Scaleform::KeyModifiers)0x80, 0);
            else
              Scaleform::GFx::KeyboardState::SetKeyUp(v21, 164, 0, (Scaleform::KeyModifiers)0x80, 0);
            break;
        }
      }
      Scaleform::GFx::InputEventsQueue::AddKeyUp(
        &this->InputEventsQueue,
        SLOWORD(event[1].Type),
        event[1].Modifiers.States,
        event->Modifiers,
        event[2].Modifiers.States);
      return 3;
    case KillFocus:
      Scaleform::GFx::MovieImpl::OnMovieFocus(this, 0);
      goto LABEL_65;
    case Char:
      Scaleform::GFx::InputEventsQueue::AddCharTyped(&this->InputEventsQueue, event[1].Type, event[1].Modifiers.States);
      return 3;
    case IME:
      v22 = (Scaleform::RefCountVImpl *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
      if ( !v22 )
        goto LABEL_65;
      v23 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::MovieImpl *, const Scaleform::GFx::Event *))v22->__vftable[1].AddRef)(
              v22,
              this,
              event);
      Scaleform::RefCountImpl::Release(v22);
      v4 = v23;
      break;
    default:
LABEL_65:
      v4 = 0;
      break;
  }
  return v4;
}
