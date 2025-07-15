void __userpurge survarium::generic_anomaly::generic_anomaly(
        survarium::generic_anomaly *this@<ecx>,
        survarium::generic_anomaly_core *a2@<esi>,
        survarium::base_game_scene *w)
{
  survarium::generic_anomaly_core::generic_anomaly_core(a2);
  a2[1].survarium::link_resolver::__vftable = (survarium::generic_anomaly_core_vtbl *)w;
  a2->survarium::link_resolver::__vftable = (survarium::generic_anomaly_core_vtbl *)&survarium::generic_anomaly::`vftable'{for `survarium::link_resolver'};
  a2->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::generic_anomaly::`vftable'{for `survarium::player_actions_subscriber'};
}
