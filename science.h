#ifndef LOL_SCIENCE
#define LOL_SCIENCE

#include <stdio.h>
#include <gmp.h>

void get_science() {
	char p[1234] = "998105607101550424389984756712634087269602770804390716721284448700611371302544845505323612788924709368589848557853610027964910806243767148320057575413364002153922407454749298656155365304084735674806899028067648502561431233330036613219536925262270578700276598416694003604478894022659850437449564391174073759761439249471852833605919569216850715907728871973765269834336765742252900402297970541882968104189639874491545580854920705998485464434936035221452028184802264778951732526581107551143848746376669771483170127883808650815205709896418069210645916401172093423887649343280916658444266479490639107116093307867380968097038422483339246141849157625452673662035586473016597447342336614518667796590938872890191904947849983949619084652203165333624916988858876172143917797018954423920369261443012877358146412386738229336715371022844093198676429269992724132187460632028187936856716387195829304875621090215662543053308967467552027679509753746216209270098342366414930195353973631014067232617291851306998599132763110426201004408661236601077008925941107778845031181538404719651074113806060928378895921049898814347409983293947125278530565508439462056310570709893641076123065725922385802418936289987147369337112159705823441216852296791750277901931603";
	mpz_t m_p;
	mpz_set_str(m_p, p, 10);
	gmp_printf ("%g\n", m_p);
}

#endif