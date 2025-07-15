void __fastcall survarium::npc_stats::set_stats(survarium::npc_stats *this, int a2)
{
  vostok::ai::npc_statistics *v4; // ecx
  survarium::human_npc *v5; // ecx
  vostok::ai::statistics_item<46,16> *m_begin; // esi
  vostok::ui::text *v7; // ecx
  const vostok::ui::window *v8; // eax
  vostok::ui::text *new_group; // eax
  int v10; // ebx
  const vostok::ui::window *v11; // eax
  vostok::ai::statistics_item<46,16> *v12; // ebx
  int v13; // esi
  int v14; // esi
  const vostok::ui::window *v15; // eax
  vostok::ui::text *v16; // eax
  const vostok::ui::window *v17; // eax
  vostok::ui::text *v18; // ecx
  unsigned int v19; // esi
  const vostok::ui::window *v20; // eax
  const vostok::ui::window *v21; // eax
  vostok::ui::text *v22; // ecx
  unsigned int v23; // esi
  const vostok::ui::window *v24; // eax
  vostok::ui::text *v25; // ecx
  unsigned int v26; // esi
  int v27; // ebx
  const vostok::ui::window *v28; // eax
  vostok::ai::statistics_item<46,16> *v29; // esi
  vostok::ai::npc_statistics *v30; // ecx
  unsigned int v31; // ebx
  const vostok::ui::window *v32; // eax
  const vostok::ui::window *v33; // eax
  survarium::npc_stats *v34; // [esp-8h] [ebp-7868h]
  int v35; // [esp+0h] [ebp-7860h]
  int v36; // [esp+0h] [ebp-7860h]
  int v37; // [esp+0h] [ebp-7860h]
  int v38; // [esp+0h] [ebp-7860h]
  float v39; // [esp+4h] [ebp-785Ch]
  float v40; // [esp+4h] [ebp-785Ch]
  float v41; // [esp+4h] [ebp-785Ch]
  float v42; // [esp+4h] [ebp-785Ch]
  survarium::npc_stats *v43; // [esp+10h] [ebp-7850h]
  survarium::npc_stats *v44; // [esp+10h] [ebp-7850h]
  survarium::npc_stats *v45; // [esp+10h] [ebp-7850h]
  unsigned int v46; // [esp+14h] [ebp-784Ch]
  unsigned int j; // [esp+14h] [ebp-784Ch]
  vostok::ui::text *v48; // [esp+14h] [ebp-784Ch]
  unsigned int v49; // [esp+18h] [ebp-7848h]
  unsigned int v50; // [esp+18h] [ebp-7848h]
  unsigned int v51; // [esp+18h] [ebp-7848h]
  int i; // [esp+1Ch] [ebp-7844h]
  int k; // [esp+1Ch] [ebp-7844h]
  vostok::ai::npc_statistics stats; // [esp+20h] [ebp-7840h] BYREF
  int savedregs; // [esp+7860h] [ebp+0h] BYREF

  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 4) + 72))(*(_DWORD *)(a2 + 4));
  if ( this )
  {
    vostok::ai::npc_statistics::npc_statistics(v4, (int)&stats);
    survarium::human_npc::fill_stats(v5, (int)this, &stats);
    m_begin = stats.sensors_state.m_begin;
    v7 = 0;
    v46 = 0;
    if ( stats.sensors_state.m_end - stats.sensors_state.m_begin )
    {
      v43 = 0;
      do
      {
        if ( v7 )
        {
          v8 = v7->w(v7);
          m_begin = stats.sensors_state.m_begin;
        }
        else
        {
          v8 = 0;
        }
        new_group = survarium::npc_stats::create_new_group(
                      v43,
                      0,
                      (int)&savedregs,
                      (float *)a2,
                      *(int *)((char *)&m_begin->caption.m_begin + (_DWORD)v43),
                      column_1,
                      *(_DWORD *)(a2 + 8),
                      *(const char **)((char *)&m_begin->caption.m_begin + (_DWORD)v43),
                      v8,
                      v35,
                      v39);
        v49 = 0;
        for ( i = 0; ; ++i )
        {
          m_begin = stats.sensors_state.m_begin;
          v7 = new_group;
          v10 = *(_DWORD *)((char *)&v43[1].m_medium_column_width + (unsigned int)stats.sensors_state.m_begin)
              - *(_DWORD *)((char *)&v43[1].m_line_height + (unsigned int)stats.sensors_state.m_begin);
          if ( v49 >= v10 / 60 )
            break;
          if ( new_group )
          {
            v11 = new_group->w(new_group);
            m_begin = stats.sensors_state.m_begin;
          }
          else
          {
            v11 = 0;
          }
          new_group = survarium::npc_stats::create_new_group(
                        (survarium::npc_stats *)(*(vostok::fixed_string<46> **)((char *)&m_begin->content.m_begin
                                                                              + (_DWORD)v43))[i].m_begin,
                        v10,
                        (int)&savedregs,
                        (float *)a2,
                        i * 60,
                        column_1,
                        *(_DWORD *)(a2 + 12),
                        (*(vostok::fixed_string<46> **)((char *)&m_begin->content.m_begin + (_DWORD)v43))[i].m_begin,
                        v11,
                        v35,
                        v39);
          ++v49;
        }
        ++v46;
        v43 = (survarium::npc_stats *)((char *)v43 + 1012);
      }
      while ( v46 < stats.sensors_state.m_end - stats.sensors_state.m_begin );
    }
    v12 = stats.selectors_state.m_begin;
    v13 = (char *)stats.selectors_state.m_end - (char *)stats.selectors_state.m_begin;
    v50 = 0;
    if ( stats.selectors_state.m_end - stats.selectors_state.m_begin )
    {
      v14 = 0;
      v44 = 0;
      while ( 1 )
      {
        if ( v7 )
        {
          v15 = v7->w(v7);
          v12 = stats.selectors_state.m_begin;
        }
        else
        {
          v15 = 0;
        }
        v16 = survarium::npc_stats::create_new_group(
                v44,
                *(int *)((char *)&v12->caption.m_begin + (_DWORD)v44),
                (int)&savedregs,
                (float *)a2,
                0,
                column_1,
                *(_DWORD *)(a2 + 8),
                *(const char **)((char *)&v12->caption.m_begin + (_DWORD)v44),
                v15,
                v35,
                v39);
        for ( j = 0; ; ++j )
        {
          v12 = stats.selectors_state.m_begin;
          v7 = v16;
          if ( j >= (*(_DWORD *)((char *)&v44[1].m_medium_column_width + (unsigned int)stats.selectors_state.m_begin)
                   - *(_DWORD *)((char *)&v44[1].m_line_height + (unsigned int)stats.selectors_state.m_begin))
                  / 60 )
            break;
          if ( v16 )
          {
            v17 = v16->w(v16);
            v12 = stats.selectors_state.m_begin;
          }
          else
          {
            v17 = 0;
          }
          v34 = (survarium::npc_stats *)(*(vostok::fixed_string<46> **)((char *)&v12->content.m_begin + (_DWORD)v44))[v14].m_begin;
          v16 = survarium::npc_stats::create_new_group(
                  v34,
                  (int)v12,
                  (int)&savedregs,
                  (float *)a2,
                  v14 * 60,
                  column_1,
                  *(_DWORD *)(a2 + 12),
                  (const char *)v34,
                  v17,
                  v35,
                  v39);
          ++v14;
        }
        ++v50;
        v44 = (survarium::npc_stats *)((char *)v44 + 1012);
        v13 = (char *)stats.selectors_state.m_end - (char *)stats.selectors_state.m_begin;
        if ( v50 >= stats.selectors_state.m_end - stats.selectors_state.m_begin )
          break;
        v14 = 0;
      }
    }
    v18 = survarium::npc_stats::create_new_group(
            (survarium::npc_stats *)stats.working_memory_state.caption.m_begin,
            (int)v12,
            (int)&savedregs,
            (float *)a2,
            v13,
            column_2,
            *(_DWORD *)(a2 + 8),
            stats.working_memory_state.caption.m_begin,
            0,
            v35,
            v39);
    v19 = 0;
    if ( stats.working_memory_state.content.m_end - stats.working_memory_state.content.m_begin )
    {
      v12 = 0;
      do
      {
        if ( v18 )
          v20 = v18->w(v18);
        else
          v20 = 0;
        v18 = survarium::npc_stats::create_new_group(
                *(survarium::npc_stats **)((char *)&stats.working_memory_state.content.m_begin->m_begin
                                         + (unsigned int)v12),
                (int)v12,
                (int)&savedregs,
                (float *)a2,
                v19++,
                column_2,
                *(_DWORD *)(a2 + 12),
                *(const char **)((char *)&stats.working_memory_state.content.m_begin->m_begin + (unsigned int)v12),
                v20,
                v36,
                v40);
        v12 = (vostok::ai::statistics_item<46,16> *)((char *)v12 + 44);
      }
      while ( v19 < stats.working_memory_state.content.m_end - stats.working_memory_state.content.m_begin );
    }
    if ( v18 )
      v21 = v18->w(v18);
    else
      v21 = 0;
    v22 = survarium::npc_stats::create_new_group(
            (survarium::npc_stats *)stats.blackboard_state.caption.m_begin,
            (int)v12,
            (int)&savedregs,
            (float *)a2,
            v19,
            column_2,
            *(_DWORD *)(a2 + 8),
            stats.blackboard_state.caption.m_begin,
            v21,
            v36,
            v40);
    v23 = 0;
    if ( stats.blackboard_state.content.m_end - stats.blackboard_state.content.m_begin )
    {
      v12 = 0;
      do
      {
        if ( v22 )
          v24 = v22->w(v22);
        else
          v24 = 0;
        v22 = survarium::npc_stats::create_new_group(
                *(survarium::npc_stats **)((char *)&stats.blackboard_state.content.m_begin->m_begin + (unsigned int)v12),
                (int)v12,
                (int)&savedregs,
                (float *)a2,
                v23++,
                column_2,
                *(_DWORD *)(a2 + 12),
                *(const char **)((char *)&stats.blackboard_state.content.m_begin->m_begin + (unsigned int)v12),
                v24,
                v37,
                v41);
        v12 = (vostok::ai::statistics_item<46,16> *)((char *)v12 + 76);
      }
      while ( v23 < stats.blackboard_state.content.m_end - stats.blackboard_state.content.m_begin );
    }
    v25 = survarium::npc_stats::create_new_group(
            (survarium::npc_stats *)stats.general_state.caption.m_begin,
            (int)v12,
            (int)&savedregs,
            (float *)a2,
            v23,
            column_3,
            *(_DWORD *)(a2 + 8),
            stats.general_state.caption.m_begin,
            0,
            v37,
            v41);
    v26 = 0;
    if ( stats.general_state.content.m_end - stats.general_state.content.m_begin )
    {
      v27 = 0;
      do
      {
        if ( v25 )
          v28 = v25->w(v25);
        else
          v28 = 0;
        v25 = survarium::npc_stats::create_new_group(
                (survarium::npc_stats *)stats.general_state.content.m_begin[v27].m_begin,
                v27 * 76,
                (int)&savedregs,
                (float *)a2,
                v26++,
                column_3,
                *(_DWORD *)(a2 + 12),
                stats.general_state.content.m_begin[v27].m_begin,
                v28,
                v38,
                v42);
        ++v27;
      }
      while ( v26 < stats.general_state.content.m_end - stats.general_state.content.m_begin );
    }
    v29 = stats.body_state.m_begin;
    v30 = 0;
    v45 = 0;
    if ( stats.body_state.m_end - stats.body_state.m_begin )
    {
      v31 = 0;
      while ( 1 )
      {
        if ( v30 )
        {
          v32 = (const vostok::ui::window *)(*(int (__thiscall **)(vostok::ai::npc_statistics *))&v30->sensors_state.m_begin->caption.m_buffer[16])(v30);
          v29 = stats.body_state.m_begin;
        }
        else
        {
          v32 = 0;
        }
        v48 = survarium::npc_stats::create_new_group(
                *(survarium::npc_stats **)(a2 + 8),
                v31 * 1012,
                (int)&savedregs,
                (float *)a2,
                (int)v29[v31].caption.m_begin,
                column_4,
                *(_DWORD *)(a2 + 8),
                v29[v31].caption.m_begin,
                v32,
                v38,
                v42);
        v51 = 0;
        for ( k = 0; ; ++k )
        {
          v29 = stats.body_state.m_begin;
          if ( v51 >= stats.body_state.m_begin[v31].content.m_end - stats.body_state.m_begin[v31].content.m_begin )
            break;
          if ( v48 )
          {
            v33 = v48->w(v48);
            v29 = stats.body_state.m_begin;
          }
          else
          {
            v33 = 0;
          }
          ++v51;
          v48 = survarium::npc_stats::create_new_group(
                  (survarium::npc_stats *)v29[v31].content.m_begin[k].m_begin,
                  v31 * 1012,
                  (int)&savedregs,
                  (float *)a2,
                  k * 60,
                  column_4,
                  *(_DWORD *)(a2 + 12),
                  v29[v31].content.m_begin[k].m_begin,
                  v33,
                  v38,
                  v42);
        }
        v45 = (survarium::npc_stats *)((char *)v45 + 1);
        v30 = (vostok::ai::npc_statistics *)((char *)stats.body_state.m_end - (char *)stats.body_state.m_begin);
        ++v31;
        if ( (unsigned int)v45 >= stats.body_state.m_end - stats.body_state.m_begin )
          break;
        v30 = (vostok::ai::npc_statistics *)v48;
      }
    }
    vostok::ai::npc_statistics::~npc_statistics(v30, (int *)&stats);
  }
}
