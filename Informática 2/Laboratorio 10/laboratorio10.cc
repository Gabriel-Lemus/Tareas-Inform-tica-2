// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: Trabajando con clases y herencia.

#include <iostream>
#include <vector>

class Avion
{
public:
    // Constructores
    Avion()
    {
        this->velocidad = 0;
        this->altitud = 0;
    }

    Avion(int velocidad, int altitud)
    {
        this->velocidad = velocidad;
        this->altitud = altitud;
    }

    // Getters
    int getVelocidad()
    {
        return velocidad;
    }

    int getAltitud()
    {
        return altitud;
    }

    // Setters
    void setVelocidad(const int velocidad)
    {
        this->velocidad = velocidad;
    }

    void setAltitud(const int altitud)
    {
        this->altitud = altitud;
    }

    // Método que establece la eficiencia en el consumo de combustible del avión según la altitud a la que se encuentre.
    void establecerEficiencia()
    {
        for (int i = 1; i < (int)nivelesDeEficiencia.size(); i++)
        {
            if (altitud <= alturasDeEficiencia[i] && altitud > alturasDeEficiencia[i - 1])
            {
                this->eficiencia = nivelesDeEficiencia[i];
                break;
            }
        }
    }

    // Método que establece la velocidad máxima, altitud máxima, y los niveles de eficiencia del avión según las
    // especificaciones de altitud. Se asume que ambos vectores tienen la misma cantidad de elementos.
    void iniciarAvion(const int velocidadMaxima, const int altitudMaxima, const std::vector<float> nivelesDeEficiencia, const std::vector<int> alturasDeEficiencia)
    {
        this->velocidadMaxima = velocidadMaxima;
        this->altitudMaxima = altitudMaxima;

        // Ciclo para establecer las altitudes a las cuales el consumo de combustible cambia.
        for (int i = 0; i < (int)alturasDeEficiencia.size(); i++)
            this->alturasDeEficiencia.push_back(alturasDeEficiencia[i]);

        // Ciclo para establecer los niveles de eficiencia del consumo de combustible, según la altitud a la que viaja el avión.
        for (int i = 0; i < (int)nivelesDeEficiencia.size(); i++)
            this->nivelesDeEficiencia.push_back(nivelesDeEficiencia[i]);

        establecerEficiencia();
    }

    // Método destructor
    ~Avion() {}

    // Ejercicio #1 - Métodos ====================================================================================================
    // Método que verifica si se puede realizar un aumento o disminución de la velocidad.
    bool acelerar(const int cambioDeVelocidad)
    {
        int posibleVelocidad = this->velocidad += cambioDeVelocidad;

        if (posibleVelocidad >= 0 && posibleVelocidad <= velocidadMaxima)
        {
            this->velocidad = posibleVelocidad;
            return true;
        }

        else
            return false;
    }

    // Método que verifica si es posible aumentar o disminuir la altitud del avión.
    // Si es posible realizar el cambio, se realiza y se retorna true.
    bool ascender(const int altitud)
    {
        int posibleAltitud = this->altitud + altitud;

        if (posibleAltitud >= 0 && posibleAltitud <= altitudMaxima)
        {
            for (int i = 0; i < (int)nivelesDeEficiencia.size(); i++)
            {
                if (posibleAltitud <= alturasDeEficiencia[i])
                    eficiencia = nivelesDeEficiencia[i];
            }

            this->altitud = posibleAltitud;

            return true;
        }

        else
            return false;
    }

    // Método que retorna el consumo actual del avión de acuerdo con su eficiencia de consumo
    // de combustible y velocidad actual.
    float getConsumoActual()
    {
        return this->eficiencia * this->velocidad;
    }

    // Ejercicio #1 - Miembros ====================================================================================================
private:
    int velocidad;
    int altitud;

protected:
    float eficiencia = 0;
    int velocidadMaxima;
    int altitudMaxima;
    std::vector<int> alturasDeEficiencia;
    std::vector<float> nivelesDeEficiencia;
};

// Ejercicio #2 ====================================================================================================
class Concorde : public Avion
{
public:
    // Método que establece los miembros requeridos del objeto Concorde.
    void inicializarConcorde()
    {
        std::vector<float> vNivelesDeEficiencia{4.0, 2.0, 1.5, 1.0};
        std::vector<int> vAlturasDeEficiencia{29999, 39999, 49999, 60000};

        iniciarAvion(2350, 60000, vNivelesDeEficiencia, vAlturasDeEficiencia);
    }

    // Constructores
    Concorde() : Avion()
    {
        inicializarConcorde();
    }

    Concorde(const int velocidad, const int altitud) : Avion(velocidad, altitud)
    {
        inicializarConcorde();
    }

    // Destructor
    ~Concorde() {}
};

class A320 : public Avion
{
public:
    // Método que establece los miembros requeridos del objeto A320.
    void inicializarA320()
    {
        std::vector<float> vNivelesDeEficiencia{2.0, 1.3, 1.0};
        std::vector<int> vAlturasDeEficiencia{19999, 29999, 40000};

        iniciarAvion(2350, 60000, vNivelesDeEficiencia, vAlturasDeEficiencia);
    }

    // Constructores
    A320() : Avion()
    {
        inicializarA320();
    }

    A320(const int velocidad, const int altitud) : Avion(velocidad, altitud)
    {
        inicializarA320();
    }

    // Destructor
    ~A320() {}
};

class EMB130 : public Avion
{
public:
    // Método que establece los miembros requeridos del objeto EMB130.
    void inicializarEMB130()
    {
        std::vector<float> vNivelesDeEficiencia{1.7, 1.2, 1.0};
        std::vector<int> vAlturasDeEficiencia{4999, 14999, 30000};

        iniciarAvion(2350, 60000, vNivelesDeEficiencia, vAlturasDeEficiencia);
    }

    // Constructores
    EMB130() : Avion()
    {
        inicializarEMB130();
    }

    EMB130(const int velocidad, const int altitud) : Avion(velocidad, altitud)
    {
        inicializarEMB130();
    }

    // Destructor
    ~EMB130() {}
};

// Función main para comprobar el funcionamiento correcto de las clases creadas.
int main()
{
    Concorde conc(1500, 30000);
    A320 a320(950, 25000);
    EMB130 emb130(500, 30000);

    printf("El Concorde viaja a una velocidad de %i Km/h, a una altitud de %i pies, con una eficiencia de %.2f.\n\n",
           conc.getVelocidad(), conc.getAltitud(), conc.getConsumoActual());

    bool ascensoPosible = conc.ascender(25000);
    bool aceleracionPosible = conc.acelerar(500);

    std::string ascenso = (ascensoPosible) ? "El ascenso del Concorde fue posible." : "El Concorde no pudo ascender.";
    std::string aceleracion = (aceleracionPosible) ? "El Concorde pudo acelerar." : "El Concorde no pudo acelerar.";

    printf("%s\n", ascenso.c_str());
    printf("%s\n\n", aceleracion.c_str());

    printf("Ahora, el Concorde viaja a una velocidad de %i Km/h, a una altitud de %i pies, con una eficiencia de %.2f.\n",
           conc.getVelocidad(), conc.getAltitud(), conc.getConsumoActual());

    return 0;
}
