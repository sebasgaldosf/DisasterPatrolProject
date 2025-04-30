#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace DisasterPatrol {
	public ref class Graph {

	private:
		array<array<int>^>^ adjacencyMatrix;
		int numVertices;

	public:
		// Constructor para inicializar el grafo con un número de vértices
		// El numero de vertices se define en base al numero de metros de un lado del area por recorrer
		Graph(int metros) {
			numVertices = metros / 0.2;
			adjacencyMatrix = gcnew array<array<int>^>(numVertices);
			for (int i = 0; i < numVertices; i++) {
				adjacencyMatrix[i] = gcnew array<int>(numVertices);
				// Inicializar todos los elementos de la matriz a 0 (sin arista)
				for (int j = 0; j < numVertices; j++) {
					adjacencyMatrix[i][j] = 0;
				}
			}
		}

		// Método para agregar una arista dirigida desde v1 a v2
		void addDirectedEdge(int v1, int v2) {
			if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
				adjacencyMatrix[v1][v2] = 1;
			}
			else {
				Console::WriteLine("Vértice inválido.");
			}
		}

		// Método para eliminar una arista dirigida desde v1 a v2
		void removeDirectedEdge(int v1, int v2) {
			if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
				adjacencyMatrix[v1][v2] = 0;
			}
			else {
				Console::WriteLine("Vértice inválido.");
			}
		}

		// Método para verificar si existe una arista entre dos vértices
		bool hasEdge(int v1, int v2) {
			if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
				return adjacencyMatrix[v1][v2] == 1;
			}
			else {
				return false;
			}
		}

		// Método para imprimir la matriz de adyacencia
		void printAdjacencyMatrix() {
			Console::Write(" ");
			for (int i = 0; i < numVertices; i++) {
				Console::Write(gcnew String(97 + i, 1) + "  ");
			}
			Console::WriteLine();
			Console::WriteLine("--");
			for (int i = 0; i < numVertices; i++) {
				Console::Write(gcnew String(97 + i, 1) + "| ");
				for (int j = 0; j < numVertices; j++) {
					Console::Write(adjacencyMatrix[i][j] + " ");
				}
				Console::WriteLine();
			}
		}

		// Propiedad para obtener el número de vértices
		property int NumberOfVertices {
			int get() {
				return numVertices;
			}
		}
	};
}
