void __userpurge survarium::stats_row::create(
        survarium::flash_text_manager *text_manager_in@<eax>,
        survarium::flash_text_manager *a2@<ecx>,
        const vostok::math::color *a3@<ebx>,
        float a4@<edi>,
        float a5@<esi>,
        survarium::stats_row *this,
        survarium::flash_text *caption_string,
        float start_width,
        float start_height,
        float caption_width,
        float column0_width,
        float column1_width,
        float column2_width,
        float column3_width,
        float color,
        char a16)
{
  float v16; // edi
  survarium::flash_text_manager *v18; // ecx
  survarium::flash_text *text; // eax
  int v20; // eax
  Scaleform::GFx::DrawText *text_impl; // ecx
  Scaleform::Render::Rect<float> *v22; // eax
  Scaleform::GFx::DrawText *v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm1_4
  survarium::flash_text_manager *v26; // ecx
  survarium::flash_text *v27; // eax
  int v28; // eax
  Scaleform::GFx::DrawText *v29; // ecx
  char v30; // cl
  char v31; // dl
  char v32; // dl
  Scaleform::Render::Rect<float> *v33; // eax
  Scaleform::GFx::DrawText *v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm1_4
  survarium::flash_text_manager *v37; // ecx
  survarium::flash_text *v38; // eax
  int v39; // eax
  Scaleform::GFx::DrawText *v40; // ecx
  char v41; // cl
  char v42; // dl
  char v43; // dl
  Scaleform::Render::Rect<float> *v44; // eax
  Scaleform::GFx::DrawText *v45; // ecx
  float v46; // xmm0_4
  float v47; // xmm1_4
  survarium::flash_text_manager *v48; // ecx
  survarium::flash_text *v49; // eax
  int v50; // eax
  Scaleform::GFx::DrawText *v51; // ecx
  char v52; // cl
  char v53; // dl
  char v54; // dl
  Scaleform::Render::Rect<float> *v55; // eax
  Scaleform::GFx::DrawText *v56; // ecx
  float v57; // xmm0_4
  float v58; // xmm1_4
  survarium::flash_text_manager *v59; // ecx
  survarium::flash_text *v60; // eax
  int v61; // eax
  Scaleform::GFx::DrawText *v62; // ecx
  char v63; // cl
  char v64; // dl
  char v65; // dl
  Scaleform::Render::Rect<float> *v66; // eax
  Scaleform::GFx::DrawText *v67; // ecx
  float v68; // xmm0_4
  float v69; // xmm1_4
  int *v70; // eax
  __int64 start_widtha; // [esp+48h] [ebp-4Ch]
  float v72; // [esp+50h] [ebp-44h]
  float v74; // [esp+54h] [ebp-40h]
  const char *v75; // [esp+54h] [ebp-40h]
  int v76; // [esp+54h] [ebp-40h]
  float v78; // [esp+58h] [ebp-3Ch]
  int v79; // [esp+58h] [ebp-3Ch]
  const vostok::math::color *v80; // [esp+5Ch] [ebp-38h]
  int v81; // [esp+5Ch] [ebp-38h]
  char v82; // [esp+6Ch] [ebp-28h]
  char v83; // [esp+70h] [ebp-24h]
  char v84[20]; // [esp+74h] [ebp-20h] BYREF
  int v85; // [esp+88h] [ebp-Ch]
  int v86; // [esp+8Ch] [ebp-8h]
  int v87; // [esp+90h] [ebp-4h]
  const char *savedregs; // [esp+94h] [ebp+0h]

  v16 = start_height;
  v72 = start_height;
  this->text_manager = text_manager_in;
  survarium::stats_stream::create(
    text_manager_in,
    a2,
    &this->packets,
    325.0,
    start_width,
    (const vostok::math::color *)LODWORD(v72),
    a4,
    a5,
    a3);
  survarium::stats_stream::create(
    text_manager_in,
    (survarium::flash_text_manager *)&this->messages,
    &this->messages,
    665.0,
    start_width,
    (const vostok::math::color *)LODWORD(v16),
    v74,
    v78,
    v80);
  text = survarium::flash_text_manager::create_text(v18, (int)this->text_manager, (int)v84, caption_string, v75);
  *(_QWORD *)&this->caption.text_impl = *(_QWORD *)&text->text_impl;
  v20 = *(_DWORD *)&text->visible;
  *(_DWORD *)&this->caption.visible = v20;
  if ( (_BYTE)v20 != 1 )
  {
    text_impl = this->caption.text_impl;
    this->caption.visible = 1;
    text_impl->SetVisible(text_impl, 1);
    this->caption.owner->need_capture = 1;
  }
  v83 = *(_BYTE *)(LODWORD(start_height) + 2);
  v82 = *(_BYTE *)(LODWORD(start_height) + 1);
  HIBYTE(start_widtha) = 0;
  BYTE2(start_widtha) = *(_BYTE *)LODWORD(start_height);
  BYTE1(start_widtha) = v82;
  LOBYTE(start_widtha) = v83;
  *(_DWORD *)((char *)&start_widtha + 3) = *(unsigned __int8 *)(LODWORD(start_height) + 3);
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, _DWORD, _DWORD, int, int, int, int))this->caption.text_impl->SetColor)(
    this->caption.text_impl,
    start_widtha,
    HIDWORD(start_widtha),
    -1,
    v76,
    v79,
    v81);
  this->caption.owner->need_capture = 1;
  v22 = this->caption.text_impl->GetRect(this->caption.text_impl, &a16);
  v23 = this->caption.text_impl;
  v24 = (float)(v22->x2 - v22->x1) + 150.0;
  v25 = (float)(v22->y2 - v22->y1) + start_width;
  column1_width = 150.0;
  column2_width = start_width;
  column3_width = v24;
  color = v25;
  v23->SetRect(v23, (const Scaleform::Render::Rect<float> *)&column1_width);
  this->caption.owner->need_capture = 1;
  v27 = survarium::flash_text_manager::create_text(
          v26,
          (int)this->text_manager,
          (int)&column1_width,
          (survarium::flash_text *)&buf,
          savedregs);
  *(_QWORD *)&this->data_bytes.text_impl = *(_QWORD *)&v27->text_impl;
  v28 = *(_DWORD *)&v27->visible;
  *(_DWORD *)&this->data_bytes.visible = v28;
  if ( (_BYTE)v28 != 1 )
  {
    v29 = this->data_bytes.text_impl;
    this->data_bytes.visible = 1;
    v29->SetVisible(v29, 1);
    this->data_bytes.owner->need_capture = 1;
  }
  v30 = *(_BYTE *)(LODWORD(start_height) + 3);
  LOBYTE(caption_width) = *(_BYTE *)(LODWORD(start_height) + 2);
  v31 = *(_BYTE *)(LODWORD(start_height) + 1);
  v87 = -1;
  LOBYTE(column0_width) = v31;
  v32 = *(_BYTE *)LODWORD(start_height);
  v86 = 0;
  BYTE2(v85) = v32;
  BYTE1(v85) = LOBYTE(column0_width);
  LOBYTE(v85) = LOBYTE(caption_width);
  HIBYTE(v85) = v30;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))this->data_bytes.text_impl->SetColor)(
    this->data_bytes.text_impl,
    v85,
    0,
    -1);
  this->data_bytes.owner->need_capture = 1;
  v33 = this->data_bytes.text_impl->GetRect(this->data_bytes.text_impl, &a16);
  v34 = this->data_bytes.text_impl;
  v35 = (float)(v33->x2 - v33->x1) + 1005.0;
  v36 = (float)(v33->y2 - v33->y1) + start_width;
  column1_width = 1005.0;
  column2_width = start_width;
  column3_width = v35;
  color = v36;
  v34->SetRect(v34, (const Scaleform::Render::Rect<float> *)&column1_width);
  this->data_bytes.owner->need_capture = 1;
  v38 = survarium::flash_text_manager::create_text(
          v37,
          (int)this->text_manager,
          (int)&column1_width,
          (survarium::flash_text *)&buf,
          savedregs);
  *(_QWORD *)&this->data_bits_per_second.text_impl = *(_QWORD *)&v38->text_impl;
  v39 = *(_DWORD *)&v38->visible;
  *(_DWORD *)&this->data_bits_per_second.visible = v39;
  if ( (_BYTE)v39 != 1 )
  {
    v40 = this->data_bits_per_second.text_impl;
    this->data_bits_per_second.visible = 1;
    v40->SetVisible(v40, 1);
    this->data_bits_per_second.owner->need_capture = 1;
  }
  v41 = *(_BYTE *)(LODWORD(start_height) + 3);
  LOBYTE(caption_width) = *(_BYTE *)(LODWORD(start_height) + 2);
  v42 = *(_BYTE *)(LODWORD(start_height) + 1);
  v87 = -1;
  LOBYTE(column0_width) = v42;
  v43 = *(_BYTE *)LODWORD(start_height);
  v86 = 0;
  BYTE2(v85) = v43;
  BYTE1(v85) = LOBYTE(column0_width);
  LOBYTE(v85) = LOBYTE(caption_width);
  HIBYTE(v85) = v41;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))this->data_bits_per_second.text_impl->SetColor)(
    this->data_bits_per_second.text_impl,
    v85,
    0,
    -1);
  this->data_bits_per_second.owner->need_capture = 1;
  v44 = this->data_bits_per_second.text_impl->GetRect(this->data_bits_per_second.text_impl, &a16);
  v45 = this->data_bits_per_second.text_impl;
  v46 = (float)(v44->x2 - v44->x1) + 1105.0;
  v47 = (float)(v44->y2 - v44->y1) + start_width;
  column1_width = 1105.0;
  column2_width = start_width;
  column3_width = v46;
  color = v47;
  v45->SetRect(v45, (const Scaleform::Render::Rect<float> *)&column1_width);
  this->data_bits_per_second.owner->need_capture = 1;
  v49 = survarium::flash_text_manager::create_text(
          v48,
          (int)this->text_manager,
          (int)&column1_width,
          (survarium::flash_text *)&buf,
          savedregs);
  *(_QWORD *)&this->data_bits_per_message.text_impl = *(_QWORD *)&v49->text_impl;
  v50 = *(_DWORD *)&v49->visible;
  *(_DWORD *)&this->data_bits_per_message.visible = v50;
  if ( (_BYTE)v50 != 1 )
  {
    v51 = this->data_bits_per_message.text_impl;
    this->data_bits_per_message.visible = 1;
    v51->SetVisible(v51, 1);
    this->data_bits_per_message.owner->need_capture = 1;
  }
  v52 = *(_BYTE *)(LODWORD(start_height) + 3);
  LOBYTE(caption_width) = *(_BYTE *)(LODWORD(start_height) + 2);
  v53 = *(_BYTE *)(LODWORD(start_height) + 1);
  v87 = -1;
  LOBYTE(column0_width) = v53;
  v54 = *(_BYTE *)LODWORD(start_height);
  v86 = 0;
  BYTE2(v85) = v54;
  BYTE1(v85) = LOBYTE(column0_width);
  LOBYTE(v85) = LOBYTE(caption_width);
  HIBYTE(v85) = v52;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))this->data_bits_per_message.text_impl->SetColor)(
    this->data_bits_per_message.text_impl,
    v85,
    0,
    -1);
  this->data_bits_per_message.owner->need_capture = 1;
  v55 = this->data_bits_per_message.text_impl->GetRect(this->data_bits_per_message.text_impl, &a16);
  v56 = this->data_bits_per_message.text_impl;
  v57 = (float)(v55->x2 - v55->x1) + 1205.0;
  v58 = (float)(v55->y2 - v55->y1) + start_width;
  column1_width = 1205.0;
  column2_width = start_width;
  column3_width = v57;
  color = v58;
  v56->SetRect(v56, (const Scaleform::Render::Rect<float> *)&column1_width);
  this->data_bits_per_message.owner->need_capture = 1;
  v60 = survarium::flash_text_manager::create_text(
          v59,
          (int)this->text_manager,
          (int)&column1_width,
          (survarium::flash_text *)&buf,
          savedregs);
  *(_QWORD *)&this->messages_per_second.text_impl = *(_QWORD *)&v60->text_impl;
  v61 = *(_DWORD *)&v60->visible;
  *(_DWORD *)&this->messages_per_second.visible = v61;
  if ( (_BYTE)v61 != 1 )
  {
    v62 = this->messages_per_second.text_impl;
    this->messages_per_second.visible = 1;
    v62->SetVisible(v62, 1);
    this->messages_per_second.owner->need_capture = 1;
  }
  v63 = *(_BYTE *)(LODWORD(start_height) + 3);
  LOBYTE(caption_width) = *(_BYTE *)(LODWORD(start_height) + 2);
  v64 = *(_BYTE *)(LODWORD(start_height) + 1);
  v87 = -1;
  LOBYTE(column0_width) = v64;
  v65 = *(_BYTE *)LODWORD(start_height);
  v86 = 0;
  BYTE2(v85) = v65;
  BYTE1(v85) = LOBYTE(column0_width);
  LOBYTE(v85) = LOBYTE(caption_width);
  HIBYTE(v85) = v63;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))this->messages_per_second.text_impl->SetColor)(
    this->messages_per_second.text_impl,
    v85,
    0,
    -1);
  this->messages_per_second.owner->need_capture = 1;
  v66 = this->messages_per_second.text_impl->GetRect(this->messages_per_second.text_impl, &column2_width);
  v67 = this->messages_per_second.text_impl;
  v68 = (float)(v66->x2 - v66->x1) + 1305.0;
  v69 = (float)(v66->y2 - v66->y1) + start_width;
  start_height = 1305.0;
  caption_width = start_width;
  column0_width = v68;
  column1_width = v69;
  v67->SetRect(v67, (const Scaleform::Render::Rect<float> *)&start_height);
  this->messages_per_second.owner->need_capture = 1;
  v70 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          0x28u);
  if ( v70 )
  {
    v70[2] = 1077936128;
    v70[3] = LODWORD(infinity_17);
    v70[4] = 1157627904;
    v70[5] = 1174405120;
    *v70 = 0;
    v70[1] = 0;
    v70[6] = 0;
    v70[8] = 0;
    v70[9] = -16711936;
    this->data_bytes_per_second_graph = (survarium::stats_graph *)v70;
  }
  else
  {
    this->data_bytes_per_second_graph = 0;
  }
}
