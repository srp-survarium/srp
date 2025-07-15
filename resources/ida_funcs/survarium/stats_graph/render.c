void __userpurge survarium::stats_graph::render(
        survarium::stats_graph *this@<ecx>,
        survarium::stats_graph *renderer,
        vostok::render::ui::renderer *scene_view,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *top_margin,
        unsigned int height,
        unsigned int value_height,
        unsigned int vertices,
        unsigned int value_range)
{
  float v8; // xmm2_4
  vostok::render::ui::renderer *v9; // edi
  float m_important_value1; // xmm1_4
  vostok::render::base_command *next; // ecx
  unsigned int v12; // esi
  float m_important_value0; // xmm0_4
  int v14; // ebx
  unsigned int v15; // esi
  void *v16; // esp
  float m_time_interval; // xmm4_4
  vostok::render::base_command *v18; // ecx
  const vostok::math::float4x4 *v19; // xmm5_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  signed int v23; // ebx
  vostok::render::one_way_render_channel *m_color; // ecx
  float y; // eax
  _BYTE v26[16]; // [esp+4h] [ebp-6Ch] BYREF
  vostok::render::ui::vertex begin; // [esp+14h] [ebp-5Ch] BYREF
  __int64 v28; // [esp+30h] [ebp-40h]
  __int64 v29; // [esp+38h] [ebp-38h]
  unsigned int v30; // [esp+40h] [ebp-30h]
  int v31; // [esp+44h] [ebp-2Ch]
  int v32; // [esp+48h] [ebp-28h]
  vostok::render::ui::vertex end; // [esp+4Ch] [ebp-24h] BYREF
  unsigned int i; // [esp+68h] [ebp-8h]
  signed int heighta; // [esp+88h] [ebp+18h]

  v8 = 0.0;
  v9 = (vostok::render::ui::renderer *)renderer;
  m_important_value1 = renderer->m_important_value1;
  next = (vostok::render::base_command *)renderer->m_newest_value->next;
  v12 = 0;
  do
  {
    m_important_value0 = *(float *)&next->is_deferred_command;
    if ( v8 > m_important_value0 )
      v8 = *(float *)&next->is_deferred_command;
    if ( m_important_value0 != renderer->m_invalid_value )
    {
      if ( m_important_value0 > m_important_value1 )
        m_important_value1 = *(float *)&next->is_deferred_command;
      ++v12;
    }
    next = (vostok::render::base_command *)next->__vftable;
  }
  while ( next->next != (vostok::render::base_command *)renderer->m_newest_value );
  i = v12;
  if ( v12 >= 2 )
  {
    end.m_uv.y = m_important_value1 - v8;
    end.m_uv.x = (float)value_height;
    v14 = 0;
    while ( 2 )
    {
      switch ( v14 )
      {
        case 0:
          m_important_value0 = renderer->m_important_value0;
          v15 = -16776961;
          goto LABEL_16;
        case 1:
          m_important_value0 = renderer->m_important_value1;
          v15 = -16711681;
          goto LABEL_16;
        case 2:
          m_important_value0 = 0.0;
          v15 = -16777216;
          goto LABEL_16;
        case 3:
          survarium::stats_graph::average_value((survarium::stats_graph *)next);
          v15 = -256;
LABEL_16:
          begin.m_position.y = (float)(height
                                     + vostok::math::floor(
                                         (float)(*(float *)&clear_value - (float)(m_important_value0 / end.m_uv.y))
                                       * end.m_uv.x));
          *((float *)&v28 + 1) = begin.m_position.y;
          begin.m_position.x = FLOAT_10_0;
          m_important_value0 = 0.0;
          *(_QWORD *)&begin.m_position.elements[2] = 0;
          begin.m_color = v15;
          begin.m_uv = 0;
          LODWORD(v28) = 1151246336;
          v29 = 0;
          v30 = v15;
          v31 = 0;
          v32 = 0;
          vostok::render::ui::renderer::draw_vertices(
            (vostok::render::ui::renderer *)&end,
            top_margin,
            &begin,
            &end,
            1u,
            0);
          ++v14;
          continue;
        default:
          v16 = alloca(28 * i);
          m_time_interval = renderer->m_time_interval;
          LODWORD(end.m_position.z) = v26;
          LODWORD(end.m_position.y) = v26;
          v18 = (vostok::render::base_command *)renderer->m_newest_value->next;
          if ( (float)(renderer->m_newest_value->time - *(float *)&v18->deferred_next) > m_time_interval )
            m_time_interval = renderer->m_newest_value->time - *(float *)&v18->deferred_next;
          v19 = clear_value;
          v20 = *(float *)&v18->deferred_next;
          v21 = *(float *)&clear_value / end.m_uv.y;
          for ( i = (unsigned int)renderer->m_newest_value->next; ; v18 = (vostok::render::base_command *)i )
          {
            v22 = *(float *)&v18->is_deferred_command;
            if ( v22 != *(float *)&v9[1].m_channel )
            {
              end.m_uv.y = (float)((float)(*(float *)&v18->deferred_next - v20) / m_time_interval) * 1259.0;
              v23 = ~(~(LODWORD(end.m_uv.y) - 1) & 0x80000000) & LODWORD(end.m_uv.y);
              heighta = ~(~(COERCE_INT((float)(*(float *)&v19 - (float)(v21 * v22)) * end.m_uv.x) - 1) & 0x80000000)
                      & COERCE_UNSIGNED_INT((float)(*(float *)&v19 - (float)(v21 * v22)) * end.m_uv.x);
              end.m_color = ((v23 >> 31)
                           ^ ((158 - (unsigned __int8)(v23 >> 23) - 96 + 64) >> 31)
                           & (((v23 | 0xFF800000) << 8 >> (-98 - (v23 >> 23)))
                            - ((v23 >> 31) & ((v23 & (((1 << (-98 - (v23 >> 23) - 96)) - 1) >> 8)) == 0))))
                          + 10;
              *(float *)&v28 = (float)end.m_color;
              LODWORD(end.m_position.w) = height
                                        + ((heighta >> 31)
                                         ^ ((158 - (unsigned __int8)(heighta >> 23) - 96 + 64) >> 31)
                                         & (((heighta | 0xFF800000) << 8 >> (-98 - (heighta >> 23)))
                                          - ((heighta >> 31)
                                           & ((heighta & (((1 << (-98 - (heighta >> 23) - 96)) - 1) >> 8)) == 0))));
              *((float *)&v28 + 1) = (float)LODWORD(end.m_position.w);
              m_color = (vostok::render::one_way_render_channel *)renderer->m_color;
              y = end.m_position.y;
              v29 = 0;
              if ( LODWORD(end.m_position.y) )
              {
                *(_QWORD *)LODWORD(end.m_position.y) = v28;
                *(_QWORD *)(LODWORD(y) + 8) = v29;
                *(_DWORD *)(LODWORD(y) + 16) = m_color;
                *(_DWORD *)(LODWORD(y) + 20) = 0;
                *(_DWORD *)(LODWORD(y) + 24) = 0;
              }
              v18 = (vostok::render::base_command *)i;
              v9 = (vostok::render::ui::renderer *)renderer;
              LODWORD(end.m_position.y) = LODWORD(y) + 28;
            }
            i = (unsigned int)v18->__vftable;
            if ( (vostok::render::one_way_render_channel *)i == v9->m_channel )
              break;
          }
          vostok::render::ui::renderer::draw_vertices(
            (vostok::render::ui::renderer *)LODWORD(end.m_position.y),
            top_margin,
            (const vostok::render::ui::vertex *)LODWORD(end.m_position.z),
            (const vostok::render::ui::vertex *)LODWORD(end.m_position.y),
            1u,
            0);
          return;
      }
    }
  }
}
