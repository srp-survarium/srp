void __userpurge survarium::stats_stream::create(
        survarium::flash_text_manager *text_manager_in@<eax>,
        survarium::flash_text_manager *a2@<ecx>,
        survarium::stats_stream *this,
        float start_width,
        float start_height,
        const vostok::math::color *column0_width,
        float column1_width,
        float column2_width,
        const vostok::math::color *color)
{
  survarium::flash_text *text; // eax
  int v10; // eax
  Scaleform::GFx::DrawText *text_impl; // ecx
  Scaleform::Render::Rect<float> *v12; // eax
  Scaleform::GFx::DrawText *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm1_4
  survarium::flash_text_manager *v16; // ecx
  survarium::flash_text *v17; // eax
  int v18; // eax
  Scaleform::GFx::DrawText *v19; // ecx
  Scaleform::Render::Rect<float> *v20; // eax
  Scaleform::GFx::DrawText *v21; // ecx
  float v22; // xmm0_4
  float v23; // xmm1_4
  survarium::flash_text_manager *v24; // ecx
  survarium::flash_text *v25; // eax
  int v26; // eax
  Scaleform::GFx::DrawText *v27; // ecx
  Scaleform::Render::Rect<float> *v28; // eax
  Scaleform::GFx::DrawText *v29; // ecx
  float v30; // xmm0_4
  float v31; // xmm1_4
  survarium::flash_text_manager *v32; // ecx
  survarium::flash_text *v33; // eax
  int v34; // eax
  Scaleform::GFx::DrawText *v35; // ecx
  Scaleform::Render::Rect<float> *v36; // eax
  Scaleform::GFx::DrawText *v37; // ecx
  float v38; // xmm0_4
  float v39; // xmm1_4
  int *v40; // eax
  vostok::memory::doug_lea_allocator *f; // ecx
  int *v42; // eax
  __int64 v43; // [esp+34h] [ebp-4Ch]
  __int64 v44; // [esp+34h] [ebp-4Ch]
  __int64 v45; // [esp+34h] [ebp-4Ch]
  __int64 v46; // [esp+34h] [ebp-4Ch]
  const char *v47; // [esp+40h] [ebp-40h]
  const char *v48; // [esp+40h] [ebp-40h]
  const char *v49; // [esp+40h] [ebp-40h]
  const char *v50; // [esp+40h] [ebp-40h]
  float v51; // [esp+58h] [ebp-28h]
  float v52; // [esp+5Ch] [ebp-24h]
  float v53; // [esp+5Ch] [ebp-24h]
  float v54; // [esp+60h] [ebp-20h] BYREF
  float v55; // [esp+64h] [ebp-1Ch]
  float v56; // [esp+68h] [ebp-18h]
  float v57; // [esp+6Ch] [ebp-14h]
  _BYTE v58[16]; // [esp+70h] [ebp-10h] BYREF

  this->text_manager = text_manager_in;
  text = survarium::flash_text_manager::create_text(
           a2,
           (int)text_manager_in,
           (int)&v54,
           (survarium::flash_text *)&buf,
           v47);
  *(_QWORD *)&this->count.text_impl = *(_QWORD *)&text->text_impl;
  v10 = *(_DWORD *)&text->visible;
  *(_DWORD *)&this->count.visible = v10;
  if ( (_BYTE)v10 != 1 )
  {
    text_impl = this->count.text_impl;
    this->count.visible = 1;
    text_impl->SetVisible(text_impl, 1);
    this->count.owner->need_capture = 1;
  }
  HIBYTE(v43) = 0;
  BYTE2(v43) = column0_width->r;
  BYTE1(v43) = column0_width->g;
  LOBYTE(v43) = column0_width->b;
  *(_DWORD *)((char *)&v43 + 3) = column0_width->a;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, _DWORD, _DWORD, int))this->count.text_impl->SetColor)(
    this->count.text_impl,
    v43,
    HIDWORD(v43),
    -1);
  this->count.owner->need_capture = 1;
  v12 = this->count.text_impl->GetRect(this->count.text_impl, v58);
  v13 = this->count.text_impl;
  v14 = (float)(v12->x2 - v12->x1) + start_width;
  v15 = (float)(v12->y2 - v12->y1) + start_height;
  v54 = start_width;
  v55 = start_height;
  v56 = v14;
  v57 = v15;
  v13->SetRect(v13, (const Scaleform::Render::Rect<float> *)&v54);
  this->count.owner->need_capture = 1;
  v17 = survarium::flash_text_manager::create_text(
          v16,
          (int)this->text_manager,
          (int)&v54,
          (survarium::flash_text *)&buf,
          v48);
  *(_QWORD *)&this->bytes.text_impl = *(_QWORD *)&v17->text_impl;
  v18 = *(_DWORD *)&v17->visible;
  *(_DWORD *)&this->bytes.visible = v18;
  if ( (_BYTE)v18 != 1 )
  {
    v19 = this->bytes.text_impl;
    this->bytes.visible = 1;
    v19->SetVisible(v19, 1);
    this->bytes.owner->need_capture = 1;
  }
  HIBYTE(v44) = 0;
  BYTE2(v44) = column0_width->r;
  BYTE1(v44) = column0_width->g;
  LOBYTE(v44) = column0_width->b;
  *(_DWORD *)((char *)&v44 + 3) = column0_width->a;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, _DWORD, _DWORD, int))this->bytes.text_impl->SetColor)(
    this->bytes.text_impl,
    v44,
    HIDWORD(v44),
    -1);
  this->bytes.owner->need_capture = 1;
  v52 = start_width + 100.0;
  v20 = this->bytes.text_impl->GetRect(this->bytes.text_impl, v58);
  v21 = this->bytes.text_impl;
  v22 = (float)(v20->x2 - v20->x1) + (float)(start_width + 100.0);
  v23 = (float)(v20->y2 - v20->y1) + start_height;
  v54 = start_width + 100.0;
  v55 = start_height;
  v56 = v22;
  v57 = v23;
  v21->SetRect(v21, (const Scaleform::Render::Rect<float> *)&v54);
  this->bytes.owner->need_capture = 1;
  v25 = survarium::flash_text_manager::create_text(
          v24,
          (int)this->text_manager,
          (int)&v54,
          (survarium::flash_text *)&buf,
          v49);
  *(_QWORD *)&this->bits_per_second.text_impl = *(_QWORD *)&v25->text_impl;
  v26 = *(_DWORD *)&v25->visible;
  *(_DWORD *)&this->bits_per_second.visible = v26;
  if ( (_BYTE)v26 != 1 )
  {
    v27 = this->bits_per_second.text_impl;
    this->bits_per_second.visible = 1;
    v27->SetVisible(v27, 1);
    this->bits_per_second.owner->need_capture = 1;
  }
  HIBYTE(v45) = 0;
  BYTE2(v45) = column0_width->r;
  BYTE1(v45) = column0_width->g;
  LOBYTE(v45) = column0_width->b;
  *(_DWORD *)((char *)&v45 + 3) = column0_width->a;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, _DWORD, _DWORD, int))this->bits_per_second.text_impl->SetColor)(
    this->bits_per_second.text_impl,
    v45,
    HIDWORD(v45),
    -1);
  this->bits_per_second.owner->need_capture = 1;
  v51 = v52 + 100.0;
  v53 = v52 + 100.0;
  v28 = this->bits_per_second.text_impl->GetRect(this->bits_per_second.text_impl, v58);
  v29 = this->bits_per_second.text_impl;
  v30 = (float)(v28->x2 - v28->x1) + v53;
  v31 = (float)(v28->y2 - v28->y1) + start_height;
  v54 = v53;
  v55 = start_height;
  v56 = v30;
  v57 = v31;
  v29->SetRect(v29, (const Scaleform::Render::Rect<float> *)&v54);
  this->bits_per_second.owner->need_capture = 1;
  v33 = survarium::flash_text_manager::create_text(
          v32,
          (int)this->text_manager,
          (int)&v54,
          (survarium::flash_text *)&buf,
          v50);
  *(_QWORD *)&this->count_per_second.text_impl = *(_QWORD *)&v33->text_impl;
  v34 = *(_DWORD *)&v33->visible;
  *(_DWORD *)&this->count_per_second.visible = v34;
  if ( (_BYTE)v34 != 1 )
  {
    v35 = this->count_per_second.text_impl;
    this->count_per_second.visible = 1;
    v35->SetVisible(v35, 1);
    this->count_per_second.owner->need_capture = 1;
  }
  HIBYTE(v46) = 0;
  BYTE2(v46) = column0_width->r;
  BYTE1(v46) = column0_width->g;
  LOBYTE(v46) = column0_width->b;
  *(_DWORD *)((char *)&v46 + 3) = column0_width->a;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, _DWORD, _DWORD, int))this->count_per_second.text_impl->SetColor)(
    this->count_per_second.text_impl,
    v46,
    HIDWORD(v46),
    -1);
  this->count_per_second.owner->need_capture = 1;
  v36 = this->count_per_second.text_impl->GetRect(this->count_per_second.text_impl, v58);
  v37 = this->count_per_second.text_impl;
  v38 = (float)(v36->x2 - v36->x1) + (float)(v51 + 100.0);
  v39 = (float)(v36->y2 - v36->y1) + start_height;
  v54 = v51 + 100.0;
  v55 = start_height;
  v56 = v38;
  v57 = v39;
  v37->SetRect(v37, (const Scaleform::Render::Rect<float> *)&v54);
  this->count_per_second.owner->need_capture = 1;
  v40 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          0x28u);
  if ( v40 )
  {
    v40[2] = 1077936128;
    v40[3] = LODWORD(infinity_17);
    v40[4] = LODWORD(FLOAT_10_0);
    v40[5] = LODWORD(default_fps_3);
    *v40 = 0;
    v40[1] = 0;
    v40[6] = 0;
    v40[8] = 0;
    v40[9] = -16711936;
  }
  else
  {
    v40 = 0;
  }
  f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  this->graph = (survarium::stats_graph *)v40;
  v42 = vostok::memory::doug_lea_allocator::malloc_impl(f, 0x28u);
  if ( v42 )
  {
    v42[2] = 1077936128;
    v42[3] = LODWORD(infinity_17);
    v42[4] = 1157627904;
    v42[5] = 1174405120;
    *v42 = 0;
    v42[1] = 0;
    v42[6] = 0;
    v42[8] = 0;
    v42[9] = -16711936;
    this->bytes_per_second_graph = (survarium::stats_graph *)v42;
  }
  else
  {
    this->bytes_per_second_graph = 0;
  }
}
