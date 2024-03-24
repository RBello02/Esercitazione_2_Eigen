#include <Eigen/Eigen>
#include <iostream>

using namespace std;
using namespace Eigen;

double errore_PALU(Matrix2d A, Vector2d b, Vector2d x)
{
    Eigen::Vector2d y = A.partialPivLu().solve(b);
    double errore = 0.0;
    Eigen::Vector2d z = y - x;
    return errore = z.norm()/x.norm();
}
double errore_QR(Matrix2d A, Vector2d b, Vector2d x)
{
    Eigen::Vector2d y = A.colPivHouseholderQr().solve(b);
    double errore = 0.0;
    Eigen::Vector2d z = y - x;
    return errore = z.norm()/x.norm();
}
void stampa (double errLU, double errQR)
{
    cout<<"l'errore per la fattorizzazione PA=LU e' "<<errLU << endl;
    cout<<"l'errore per la fattorizzazione QR e' "<<errQR << endl;
}
int main()
{
    Eigen::Vector2d x;
    x <<-1.0e+0, -1.0e+00;


    Eigen::Matrix2d A1;
    A1 << 5.547001962252291e-01, -3.770900990025203e-02, 8.320502943378437e-01,
        -9.992887623566787e-01;
    Eigen::Vector2d b1;
    b1 << -5.169911863249772e-01, 1.672384680188350e-01;
    cout<<"A1, b1"<<endl;
    stampa(errore_PALU(A1,b1,x),errore_QR(A1,b1,x));

    Eigen::Matrix2d A2;
    A2 << 5.547001962252291e-01, -5.540607316466765e-01, 8.320502943378437e-01,
        -8.324762492991313e-01;
    Eigen::Vector2d b2;
    b2 << -6.394645785530173e-04, 4.259549612877223e-04;
    cout<<"A2, b2"<<endl;
    stampa(errore_PALU(A2,b2,x),errore_QR(A2,b2,x));

    Eigen::Matrix2d A3;
    A3 << 5.547001962252291e-01, -5.547001955851905e-01, 8.320502943378437e-01,
        -8.320502947645361e-01;
    Eigen::Vector2d b3;
    b3 <<-6.400391328043042e-10, 4.266924591433963e-10;
    cout<<"A3, b3"<<endl;
    stampa(errore_PALU(A3,b3,x),errore_QR(A3,b3,x));



    return 0;
}
